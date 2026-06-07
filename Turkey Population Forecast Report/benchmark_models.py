# benchmark_model.py

"""
As mentioned in the report, the ablation study with 2 other models,
one being the spatially separate model and the other is a basic linear regressor
"""

import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# --- 1. SETUP ---
HISTORICAL_DATA_PATH = 'datasets/master_dataset.csv'
VALIDATION_DATA_PATH = 'datasets/rural_vs_urban.csv'
PROPOSED_CSV_PATH = 'results/comprehensive_2030_report_proposed.csv'
RHO0_CSV_PATH = 'results/comprehensive_2030_report_rho0.csv'
TARGET_REGIONS = ['TR10', 'TR61', 'TR51']

df_hist = pd.read_csv(HISTORICAL_DATA_PATH)
df_val = pd.read_csv(VALIDATION_DATA_PATH)
df_proposed = pd.read_csv(PROPOSED_CSV_PATH)
df_rho0 = pd.read_csv(RHO0_CSV_PATH)

plt.style.use('seaborn-v0_8-whitegrid')
print("Evaluating regional predictive errors using precomputed CSV reports...")

# --- 2. COMPUTE COMPARATIVE OUT-OF-SAMPLE BENCHMARKS ---
for idx, reg_code in enumerate(TARGET_REGIONS):
    fig, ax = plt.subplots(figsize=(9, 6))

    row_hist = df_hist[df_hist['Region'].str.contains(reg_code)].sort_values('Year')
    row_val = df_val[(df_val['Region'].str.contains(reg_code)) & (df_val['Year'] == 2025)]
    row_prop = df_proposed[df_proposed['Region'].str.contains(reg_code)]
    row_r0 = df_rho0[df_rho0['Region'].str.contains(reg_code)]

    if row_val.empty or row_prop.empty or row_r0.empty:
        raise ValueError(f"Missing regional matching rows for token: {reg_code}")

    years_hist = row_hist['Year'].values
    y_hist = row_hist['Total_Population'].values
    year_val = 2025
    y_val_true = row_val['Total_Population'].values[0]

    # --- 3. MODEL A — TUNED LINEAR REGRESSION BASELINE ---
    births_past = row_hist['Total_Births'].values
    mig_past = row_hist['Net_Migration'].values
    X_train_lr = years_hist.reshape(-1, 1)
    years_recent = years_hist[-5:]

    slope_births, intercept_births = np.polyfit(years_recent, births_past[-5:], 1)
    slope_mig, intercept_mig = np.polyfit(years_recent, mig_past[-5:], 1)

    X_val_lr = np.array([[2025]])
    lr = LinearRegression()
    lr.fit(X_train_lr, y_hist)
    pred_lr_2025 = lr.predict(X_val_lr)[0]

    # --- 4. MODEL B — PROPOSED SPATIO-TEMPORAL GP ---
    pred_full_2025 = row_prop['Total_2025'].values[0]
    lower_full_2025 = row_prop['Total_2025_lower'].values[0]
    upper_full_2025 = row_prop['Total_2025_upper'].values[0]

    # --- 5. MODEL C — ABLATED NON-SPATIAL GP ---
    pred_rho0_2025 = row_r0['Total_2025'].values[0]
    lower_rho0_2025 = row_r0['Total_2025_lower'].values[0]
    upper_rho0_2025 = row_r0['Total_2025_upper'].values[0]

    # --- 6. ERROR METRICS ---
    mape_full = abs(y_val_true - pred_full_2025) / y_val_true * 100
    mape_rho0 = abs(y_val_true - pred_rho0_2025) / y_val_true * 100
    mape_lr = abs(y_val_true - pred_lr_2025) / y_val_true * 100

    print(f"\n[{reg_code} Verification Metrics]")
    print(f" Ground Truth 2025 : {y_val_true:,.0f}")
    print(f" Proposed ST-GP : {pred_full_2025:,.0f} (MAPE: {mape_full:.4f}%)")
    print(f" Ablated GP (Rho=0): {pred_rho0_2025:,.0f} (MAPE: {mape_rho0:.4f}%)")
    print(f" Linear Regression : {pred_lr_2025:,.0f} (MAPE: {mape_lr:.4f}%)")

    # --- 7. VISUALIZATION ---
    ax.plot(years_hist, y_hist, color='#0f172a', marker='o', linewidth=2.5, label='Historical Observations (2013-2024)')
    ax.axvline(2024, color='#94a3b8', linestyle=':', linewidth=1.5)
    ax.scatter(2025, y_val_true, color='#ef4444', marker='X', s=140, zorder=8, label='True 2025 Ground Truth')

    models = [
        {"pred": pred_full_2025, "low": lower_full_2025, "up": upper_full_2025, "color": '#4f46e5', "style": '-', "marker": 'd', "label": 'Proposed ST-GP Model'},
        {"pred": pred_rho0_2025, "low": lower_rho0_2025, "up": upper_rho0_2025, "color": '#0d9488', "style": '-.', "marker": '^', "label": r'Non-Spatial GP ($\rho=0$)'},
        {"pred": pred_lr_2025, "low": None, "up": None, "color": '#d97706', "style": '--', "marker": 's', "label": 'Tuned Linear Regression'}
    ]

    for m in models:
        ax.plot([2024, 2025], [y_hist[-1], m["pred"]], color=m["color"], linestyle=m["style"], marker=m["marker"], linewidth=2, markersize=7, zorder=5, label=m["label"])
        if m["low"] is not None:
            ax.fill_between([2024, 2025], [y_hist[-1], m["low"]], [y_hist[-1], m["up"]], color=m["color"], alpha=0.12, zorder=1)

    y_all = [y_hist.min(), y_hist.max(), pred_full_2025, pred_rho0_2025, pred_lr_2025, y_val_true]
    padding = (max(y_all) - min(y_all)) * 0.12

    ax.set_ylim(min(y_all) - padding, max(y_all) + padding)
    ax.set_title(f"Regional Profile Validation: {reg_code}", fontsize=14, fontweight='bold', color='#1e293b')
    ax.set_xlabel("Year", fontsize=11, color='#475569')
    ax.set_ylabel("Population", fontsize=11, color='#475569')
    ax.set_xticks([2013, 2016, 2019, 2022, 2025])
    ax.set_xlim(2012, 2026)
    ax.grid(True, linestyle='--', alpha=0.3)
    ax.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, p: f'{x / 1e6:.2f}M'))
    ax.legend(loc='upper left', fontsize=9, frameon=True, fancybox=True, shadow=False)

    plt.tight_layout()
    os.makedirs('results', exist_ok=True)
    save_path = f'results/model_validation_{reg_code}.png'
    plt.savefig(save_path, dpi=300, bbox_inches='tight')
    print(f"\nSaved validation figure: {save_path}")
    plt.show()