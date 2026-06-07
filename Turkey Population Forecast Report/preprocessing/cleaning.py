# cleaning.py

"""
After checking with EDA.ipynb I decided which features, years etc. I would need. Here I just clean based on that
"""

import pandas as pd
import numpy as np

# Define file paths
pop_file = 'datasets/rural_vs_urban.csv'
birth_file = 'datasets/births.csv'
mig_file = 'datasets/migration.csv'

df_pop = pd.read_csv(pop_file)
df_birth = pd.read_csv(birth_file)
df_mig = pd.read_csv(mig_file)

# 1. Filter time
df_pop = df_pop[(df_pop['Year'] >= 2013) & (df_pop['Year'] <= 2024)]
df_birth = df_birth[(df_birth['Year'] >= 2013) & (df_birth['Year'] <= 2024)]
df_mig = df_mig[(df_mig['Year'] >= 2013) & (df_mig['Year'] <= 2024)]

# 2. Merge
master_df = pd.merge(df_pop, df_birth, on=['Year', 'Region'], how='inner')
master_df = pd.merge(master_df, df_mig, on=['Year', 'Region'], how='inner')

# 3. Typecasting
numeric_columns = ['Rural', 'Urban', 'Total_Population', 'Total_Births', 'Net_Migration']
for col in numeric_columns:
    master_df[col] = pd.to_numeric(master_df[col], errors='coerce').fillna(0)

# 4. Sorting
master_df = master_df.sort_values(by=['Region', 'Year']).reset_index(drop=True)

print("\nFirst 10 Rows of the Master Dataset:")
print(master_df.head(10))

# 5. Saving
csv_output = 'datasets/master_dataset.csv'
master_df.to_csv(csv_output, index=False)

print(f"Saved to '{csv_output}'.")