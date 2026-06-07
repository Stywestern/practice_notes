# data_loader.py

"""
Basically a loader + preprocessor for the cleaned data.
"""

import pandas as pd
import numpy as np

class PopulationLoader:
    def __init__(self, filepath):
        self.raw_data = pd.read_csv(filepath)
        self.processed_data = None
        self.regions = sorted(self.raw_data['Region'].unique())
        
    def preprocess(self):
        df = self.raw_data.copy()
        
        # Term 0: Safe log transform
        df['log_total'] = np.log(df['Total_Population'].replace(0, 1))
        df['log_rural'] = np.log(df['Rural'].replace(0, 1))
        df['log_urban'] = np.log(df['Urban'].replace(0, 1))
        
        # Term 1: Desing matrix
        df['births_scaled'] = df['Total_Births'] / 1000
        df['migration_scaled'] = df['Net_Migration'] / 1000
        
        df['time_idx'] = df['Year'] - df['Year'].min()
        
        self.processed_data = df
        return self.processed_data

    def get_region_data(self, region_name, target_type='total'):
        # Validate target type
        target_map = {
            'total': 'log_total',
            'rural': 'log_rural',
            'urban': 'log_urban'
        }
        
        if target_type not in target_map:
            raise ValueError("target_type must be 'total', 'rural', or 'urban'")

        region_df = self.processed_data[self.processed_data['Region'] == region_name]
        
        # Select the specific Y based on the target_type
        y = region_df[target_map[target_type]].values
        
        # Design Matrix (intercept, births, migration, time)
        X = region_df[['births_scaled', 'migration_scaled', 'time_idx']].values
        X = np.hstack([np.ones((X.shape[0], 1)), X])
        
        return y, X