# pre_cleaning(other).py

"""
Same as pre_cleaning but some .xls where different
"""

import pandas as pd
import numpy as np

filepath = 'datasets/pops_migration.xls'

raw_df = pd.read_excel(filepath, header=None)

data_df = raw_df.iloc[5:, 0:3].copy()
data_df.columns = ['Year', 'Region', 'Net_Migration']
data_df['Year'] = data_df['Year'].ffill()
data_df = data_df.dropna(subset=['Region'])
data_df['Year'] = pd.to_numeric(data_df['Year'], errors='coerce')
data_df = data_df.dropna(subset=['Year']) # Drop if Year parsing failed
data_df['Year'] = data_df['Year'].astype(int)

data_df['Net_Migration'] = pd.to_numeric(data_df['Net_Migration'], errors='coerce').fillna(0)
clean_df = data_df[data_df['Year'] >= 2013].copy()

print("\nFirst 10 Rows of Cleaned Migration Data:")
print(clean_df.head(10))
csv_output = 'datasets/cleaned_migration.csv'
clean_df.to_csv(csv_output, index=False)

print(f"Data saved to '{csv_output}'.")