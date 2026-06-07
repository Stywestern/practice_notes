# generate_future.py

"""
Using calculated posteriors, generates data upto the year specified.
"""

import pickle
import numpy as np
import pandas as pd
from data_loader import PopulationLoader
from project_constants import QUEEN_MATRIX, REGIONS

import numpy as np
from scipy import linalg

from gp_kernels import compute_covariance_matrix, matern_kernel_15

class PopulationForecaster:
    def __init__(self, samples, loader, regions):
        self.samples = samples
        self.loader = loader
        self.regions = regions
        self.T_past = 12  # 2013-2024
        self.T_future = 6 # 2025-2030
        self.years_past = np.arange(self.T_past)
        self.years_future = np.arange(self.T_past, self.T_past + self.T_future)

    def forecast_region(self, region_idx, target_type='total'):
        """
        Generates 2030 projections for a specific region and population type.
        """
        region_name = self.regions[region_idx]
        
        # 1. Get the correct historical Y and X for this target
        y_past, X_past = self.loader.get_region_data(region_name, target_type=target_type)
        
        # 2. Project to X_future
        recent_drivers = X_past[-3:, 1:3].mean(axis=0)
        X_future = []
        for t in self.years_future:
            X_future.append([1.0, recent_drivers[0], recent_drivers[1], t])
        X_future = np.array(X_future)

        all_forecasts = []

        # 3. Predict the future using Posterior Samples
        for s in self.samples:
            beta = s['beta'][region_idx]
            phi = s['phi'][region_idx]
            sigma_sq = s['sigma'][region_idx]
            z_past = s['Z'][region_idx]

            K_past = compute_covariance_matrix(self.years_past, sigma_sq, phi)
            
            dist_matrix = np.abs(np.subtract.outer(self.years_future, self.years_past))
            K_cross = sigma_sq * matern_kernel_15(dist_matrix, phi)
            
            z_future = K_cross @ linalg.solve(K_past, z_past, assume_a='pos')
            
            eta_future = X_future @ beta + z_future
            all_forecasts.append(np.exp(eta_future)) 

        return np.array(all_forecasts)

    def get_summary(self, forecasts):
        """Helper to get mean and 95% Credible Intervals."""
        return {
            'mean': np.mean(forecasts, axis=0),
            'lower': np.percentile(forecasts, 2.5, axis=0),
            'upper': np.percentile(forecasts, 97.5, axis=0)
        }

if __name__ == "__main__":
    DATA_PATH = 'datasets/master_dataset.csv'
    targets = ['total', 'urban', 'rural']
    years_forecast = [2025, 2026, 2027, 2028, 2029, 2030]

    loader = PopulationLoader(DATA_PATH)
    loader.preprocess()

    model_configs = {
        'proposed': 'results/posterior_',
        'rho0': 'results/(rho0)posterior_'
    }

    for model_key, path_prefix in model_configs.items():
        print(f"\n{'='*60}")
        print(f"RUNNING FORECAST PIPELINE FOR CONFIGURATION: {model_key.upper()}")
        print(f"{'='*60}")

        # 1. Loading
        all_samples = {}
        for t in targets:
            file_path = f'{path_prefix}{t}_50k.pkl'
            print(f"Loading weights from: {file_path}")
            with open(file_path, 'rb') as f:
                all_samples[t] = pickle.load(f)

        # 2. Iterative Forecasting
        report_data = []

        for i, region in enumerate(REGIONS):
            region_results = {'Region': region}
            
            for t in targets:
                forecaster = PopulationForecaster(all_samples[t], loader, REGIONS)
                f_samples = forecaster.forecast_region(i, target_type=t)
                
                # A. Capture the 2024 baseline
                y_2024_log, _ = loader.get_region_data(region, target_type=t)
                val_2024 = int(np.exp(y_2024_log[-1]))
                region_results[f'{t.capitalize()}_2024'] = val_2024
                
                # B. Capture every forecast year mean and credible intervals
                for yr_idx, year in enumerate(years_forecast):
                    yearly_distribution = f_samples[:, yr_idx]
                    
                    mean_val = yearly_distribution.mean()
                    lower_val = np.percentile(yearly_distribution, 2.5)
                    upper_val = np.percentile(yearly_distribution, 97.5)
                    
                    region_results[f'{t.capitalize()}_{year}'] = int(mean_val)
                    region_results[f'{t.capitalize()}_{year}_lower'] = int(lower_val)
                    region_results[f'{t.capitalize()}_{year}_upper'] = int(upper_val)

            # 3. Calculate Metrics
            total_24 = region_results['Total_2024']
            total_30 = region_results['Total_2030']
            region_results['Total_Growth_%'] = ((total_30 / total_24) - 1) * 100
            
            urb_ratio_24 = region_results['Urban_2024'] / total_24
            urb_ratio_30 = region_results['Urban_2030'] / total_30
            region_results['Urb_Shift_Points'] = (urb_ratio_30 - urb_ratio_24) * 100
            
            report_data.append(region_results)

        # 4. Save and Display
        df_report = pd.DataFrame(report_data)
        df_report = df_report.sort_values(by='Region')

        output_path = f'results/comprehensive_2030_report_{model_key}.csv'
        df_report.to_csv(output_path, index=False)

        print(f"Success: Report generated for model configuration [{model_key}].")
        print(f"Saved directly to: {output_path}")