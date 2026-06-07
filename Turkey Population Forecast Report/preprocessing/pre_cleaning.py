# pre_cleaning.py
"""
This file is to convert .xls files that I donwloaded into .csv format with some tweaks
"""

import pandas as pd
import numpy as np

filepath = 'datasets/pops_rural_vs_urban.xls'

# Read and load
raw_df = pd.read_excel(filepath, header=None) # Remove header
demographic_headers = raw_df.iloc[2, 2:].tolist() # demographic headers are at index 2
new_columns = ['Year', 'Region'] + demographic_headers

data_df = raw_df.iloc[5:].copy() # data starts from index 5
data_df.columns = new_columns
data_df['Year'] = data_df['Year'].ffill()
data_df = data_df.dropna(subset=['Region'])

# melt converts pivot tables into csv like structures
df_long = data_df.melt(id_vars=['Year', 'Region'], var_name='Demographic', value_name='Population')
df_long['Population'] = pd.to_numeric(df_long['Population'], errors='coerce').fillna(0)

# Seperate urban vs rural and group
df_long['Environment'] = np.where(df_long['Demographic'].str.contains('Şehir', case=False, na=False), 'Urban', 'Rural')
df_long['Year'] = df_long['Year'].astype(int)
df_long = df_long[df_long['Year'] >= 2013]
clean_df = df_long.groupby(['Year', 'Region', 'Environment'])['Population'].sum().reset_index()
final_df = clean_df.pivot_table(index=['Year', 'Region'], columns='Environment', values='Population').reset_index()

# Calculate total population
final_df['Total_Population'] = final_df['Urban'] + final_df['Rural']

# Printing
print("\nFirst 10 Rows of Cleaned Data:")
print(final_df.head(10))

# Saving
csv_output = 'datasets/rural_vs_urban.csv'

final_df.to_csv(csv_output, index=False)

print(f"Data saved to '{csv_output}'.")