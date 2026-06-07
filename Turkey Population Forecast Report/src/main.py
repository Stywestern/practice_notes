# main.py

"""
Orchestrator file, just brings the modules together.
"""

from modules.data_loader import PopulationLoader
import matplotlib.pyplot as plt
import numpy as np
import pickle

from modules.gp_kernels import compute_covariance_matrix, compute_car_precision_matrix
from modules.project_constants import QUEEN_MATRIX, REGIONS
from modules.generate_future import PopulationForecaster

# =================================================================
# 1. SETUP & DATA INITIALIZATION
# =================================================================
DATA_PATH = r'datasets/master_dataset.csv'
TARGET = 'urban'  # Options: 'total', 'urban', 'rural'

loader = PopulationLoader(DATA_PATH)
loader.preprocess()

PICKLE_PATH = f'results/posterior_{TARGET}_50k.pkl'
with open(PICKLE_PATH, 'rb') as f:
    posterior_samples = pickle.load(f)

forecaster = PopulationForecaster(posterior_samples, loader, REGIONS)

# =================================================================
# 2. ANALYSIS & VISUALIZATION ENGINE
# =================================================================
def generate_report(region_idx, target_type='total'):
    """
    Handles the math and plotting for a specific region/target combo.
    """
    region_name = REGIONS[region_idx]
    
    # 1. Generate Forecast Samples (4,000 potential futures)
    future_samples = forecaster.forecast_region(region_idx, target_type=target_type)
    stats = forecaster.get_summary(future_samples)
    
    # 2. Get Historical Context
    y_past_log, _ = loader.get_region_data(region_name, target_type=target_type)
    y_past = np.exp(y_past_log)
    
    # 3. Visualization
    years_past = np.arange(2013, 2025)
    years_future = np.arange(2025, 2031)
    
    plt.figure(figsize=(12, 5))
    
    # Historical
    plt.plot(years_past, y_past, 'ko-', label="Historical Data", linewidth=1, markersize=4)
    
    # Projection
    plt.plot(years_future, stats['mean'], 'r--', label=f"2030 {target_type.capitalize()} Forecast")
    plt.fill_between(years_future, stats['lower'], stats['upper'], color='red', alpha=0.15, label="95% Credible Interval")
    
    plt.title(f"Spatio-Temporal Population Analysis: {region_name} ({target_type.upper()})")
    plt.ylabel("Population Count")
    plt.grid(True, alpha=0.2, linestyle='--')
    plt.legend(frameon=False)

    proj_2030 = stats['mean'][-1]
    print(f"{'='*30}")
    print(f"REPORT: {region_name}")
    print(f"{'='*30}")
    print(f"2024 (Last Observed): {y_past[-1]:,.0f}")
    print(f"2030 (Projected Mean): {proj_2030:,.0f}")
    print(f"95% Confidence Range:  {stats['lower'][-1]:,.0f} - {stats['upper'][-1]:,.0f}")
    print(f"{'='*30}\n")

# =================================================================
# 3. RUN REPORTS
# =================================================================
# Examine districts
for idx in [10, 0]: # Istanbul and Adana/Mersin
    generate_report(idx, target_type=TARGET)