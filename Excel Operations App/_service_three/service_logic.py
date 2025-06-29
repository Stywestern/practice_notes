import pandas as pd
import numpy as np

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

import base64
from io import BytesIO

from jinja2 import Environment, FileSystemLoader
from markupsafe import Markup
import json

# Register a custom 'tojson' filter
def tojson_filter(value):
    return Markup(json.dumps(value))

import os
import webbrowser

import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning)

import traceback
def log_error(context):
    with open("outputs/analyse_error_log.txt", "a") as f:
        f.write(f"\n--- Error in: {context} ---\n")
        f.write(traceback.format_exc())
        
def log_print(message: str) -> None:
    print(message)
    with open("outputs/analyse_error_log.txt", "a") as f:
        f.write(f"{message}\n")

from _config.settings import load_config
from _utils.functions import clean_sheet_name, open_file


def calculate_total_usage(group):
    """Calculates the total usage for each company on a given date and adds it as a new row."""
    total_usage = group['Acr'].sum()
    total_usage_row = pd.DataFrame({
        'TPID': [group['TPID'].iloc[0]],
        'TopParent': [group['TopParent'].iloc[0]],
        'FiscalDate': [group['FiscalDate'].iloc[0]],
        'ServiceLevel2': ['Total Usage'],
        'Acr': [total_usage]
    })
    return pd.concat([group, total_usage_row], ignore_index=True)


def flag_anomalies(df, company_col='TopParent', service_col='ServiceLevel2', date_col='FiscalDate', usage_col='Acr',
                    anomaly_threshold_percent=20, anomaly_threshold_abs=60, recent_window_size=7, shift_window=3):
    """
    Flags anomalies based on a sustained shift in usage.

    Args:
        df (pd.DataFrame): Input DataFrame with usage data.
        company_col (str): Name of the company column.
        service_col (str): Name of the service level column.
        date_col (str): Name of the date column.
        usage_col (str): Name of the usage column (Acr).
        anomaly_threshold_percent (int): Percentage change threshold for anomaly.
        anomaly_threshold_abs (int): Absolute change threshold for anomaly.
        recent_window_size (int): Number of recent data points to consider for baseline.
        shift_window (int): Number of consecutive data points exceeding the threshold to flag a shift.

    Returns:
        pd.DataFrame: DataFrame with 'anomaly' (bool) and 'anomaly_direction' (str) columns.
    """
    df_with_flags = df.copy()
    df_with_flags['anomaly'] = False
    df_with_flags['anomaly_direction'] = None

    for (company, service), group in df_with_flags.groupby([company_col, service_col]):
        group = group.sort_values(by=date_col).reset_index()  # retain original index

        # Initialize a counter for consecutive anomalies
        consecutive_anomalies = 0

        for i in range(recent_window_size, len(group)):
            historical_window = group.loc[i - recent_window_size:i - 1, usage_col]
            current_usage = group.loc[i, usage_col]

            if historical_window.empty:
                continue

            baseline_usage = historical_window.median()

            if baseline_usage != 0:
                percent_change = abs((current_usage - baseline_usage) / baseline_usage) * 100
                absolute_change = abs(current_usage - baseline_usage)

                is_single_anomaly = percent_change >= anomaly_threshold_percent and absolute_change >= anomaly_threshold_abs

                if is_single_anomaly:
                    consecutive_anomalies += 1
                    if consecutive_anomalies >= shift_window:
                        # Flag the current point and the preceding points in the shift window
                        for j in range(i - shift_window + 1, i + 1):
                            original_index = group.loc[j, 'index']
                            if not df_with_flags.loc[original_index, 'anomaly']: # Avoid overwriting direction
                                df_with_flags.loc[original_index, 'anomaly'] = True
                                df_with_flags.loc[original_index, 'anomaly_direction'] = (
                                    'increase' if group.loc[j, usage_col] > baseline_usage else 'decrease'
                                )
                else:
                    consecutive_anomalies = 0  # Reset the counter if the condition is not met

    return df_with_flags


def get_anomalous_instances(df, anomaly_col='anomaly', company_col='TopParent', service_col='ServiceLevel2',
                            date_col='FiscalDate', usage_col='Acr', shift_window=3, top_n_companies=5):
    """
    Returns all rows for (company, service) pairs that have at least one flagged anomaly.

    Args:
        df (pd.DataFrame): Input DataFrame with anomaly flags.
        anomaly_col (str): Name of the anomaly flag column (True/False).
        company_col (str): Name of the company column.
        service_col (str): Name of the service level column.
        date_col (str): Name of the date column.
        usage_col (str): Name of the usage column (Acr).
        shift_window (int): This parameter is not used in this modified version.
        top_n_companies (int): This parameter is not used in this modified version.

    Returns:
        pd.DataFrame: DataFrame containing all rows for (company, service) pairs with at least one anomaly.
    """
    anomalous_pairs = set(df[df[anomaly_col] == True][[company_col, service_col]].itertuples(index=False, name=None))

    def is_anomalous_pair(row):
        return (row[company_col], row[service_col]) in anomalous_pairs

    return df[df.apply(is_anomalous_pair, axis=1)].copy()


def plot_acr_with_outliers(dates, values, anomalies, title, save_path=None):
    """Plots Acr over time as a scatter plot, highlighting outlier points and optionally saves the plot."""
    plt.figure(figsize=(12, 6))
    plt.scatter(dates, values, label='Acr', s=30)  # Use scatter for all points
    plt.scatter(dates[anomalies], values[anomalies], color='red', label='Anomaly', s=50)
    plt.xlabel('Date')
    plt.ylabel('Acr')
    plt.legend()
    plt.grid(True)
    plt.tight_layout()

    # Format the x-axis to show only month and day
    plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%m-%d'))
    plt.gcf().autofmt_xdate() # Rotate date labels for better readability

    if save_path:
        plt.savefig(save_path)
        plt.close()
    else:
        plt.show()


def generate_flags_per_service_chart(df_anomalies_final):
    """
    Generates a horizontal bar chart showing the number of unique companies
    that have the top 10 services flagged as an anomaly.
    """
    log_print("Starting generate_flags_per_service_chart...")

    service_company_counts = {}
    for service in df_anomalies_final['ServiceLevel2'].unique():
        anomalous_service_instances = df_anomalies_final[
            (df_anomalies_final['ServiceLevel2'] == service) &
            (df_anomalies_final['anomaly'] == True)
        ]
        unique_companies = anomalous_service_instances['TopParent'].nunique()
        if unique_companies > 0:
            service_company_counts[service] = unique_companies

    log_print(f"Found {len(service_company_counts)} services with anomalies.")

    sorted_service_counts = pd.Series(service_company_counts).sort_values(ascending=False)
    top_10_services = sorted_service_counts.head(10)

    log_print(f"Top 10 services to plot: {top_10_services.to_dict()}")

    if not top_10_services.empty:
        try:
            log_print("Plotting horizontal bar chart...")
            plt.figure(figsize=(8, 6))
            plt.barh(top_10_services.index, top_10_services.values, color='#8fbc8f')
            plt.xlabel('Number of Unique Companies Flagging Service')
            plt.ylabel('Service')
            plt.title('Top 10 Services by Unique Anomalous Companies')
            plt.tight_layout()

            buffer = BytesIO()
            plt.savefig(buffer, format='png')
            buffer.seek(0)
            image_base64 = base64.b64encode(buffer.read()).decode('utf-8')
            plt.close()
            log_print("Chart successfully generated.")
            return image_base64

        except Exception as e:
            log_print(f"Error during plotting: {e}")
            return None
    else:
        log_print("No data available for plotting.")
        return None


def generate_anomaly_trend_chart(df_anomalies_final):
    """
    Generates a line chart showing the trend of the number of unique companies
    experiencing anomalies over time, with only month and day on the x-axis.
    """
    anomalies_by_date = df_anomalies_final[df_anomalies_final['anomaly'] == True].groupby('FiscalDate')['TopParent'].nunique()

    if not anomalies_by_date.empty:
        plt.figure(figsize=(8, 6))
        plt.plot(anomalies_by_date.index, anomalies_by_date.values, marker='o', linestyle='-', color='#4c72b0')
        plt.xlabel('Date')
        plt.ylabel('Number of Unique Companies with Anomalies')
        plt.title('Trend of Unique Companies with Anomalies Over Time')
        plt.grid(True)
        plt.tight_layout()

        # Format the x-axis to show only month and day
        plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%m-%d'))
        plt.gcf().autofmt_xdate() # Rotate date labels for better readability

        buffer = BytesIO()
        plt.savefig(buffer, format='png')
        buffer.seek(0)
        image_base64 = base64.b64encode(buffer.read()).decode('utf-8')
        plt.close()
        return image_base64
    else:
        return None # Return None if there's no data to plot


def generate_usage_pie_chart(total_usage_per_service):
    """
    Generates a pie chart showing the percentage of total usage for the top 10 services.
    The remaining services are grouped into an 'Other' category.
    """
    if total_usage_per_service.empty:
        return None

    # Sort services by usage in descending order
    sorted_usage = total_usage_per_service.sort_values(ascending=False)

    # Get the top 9 services (leaving space for 'Other')
    top_9_services = sorted_usage.head(9)

    # Calculate the total usage of the remaining services
    other_usage = sorted_usage[9:].sum()

    # Create data for the pie chart
    labels = top_9_services.index.tolist()
    sizes = top_9_services.values.tolist()

    if other_usage > 0:
        labels.append('Other')
        sizes.append(other_usage)

    plt.figure(figsize=(8, 8))
    plt.pie(sizes, labels=labels, autopct='%1.1f%%', startangle=140)
    plt.title('Percentage of Total Usage by Top 10 Services')
    plt.tight_layout()

    buffer = BytesIO()
    plt.savefig(buffer, format='png')
    buffer.seek(0)
    image_base64 = base64.b64encode(buffer.read()).decode('utf-8')
    plt.close()
    return image_base64


def analyse() -> None:
    log_print("Start")
    
    # === Load configuration and data ===
    try:
        config = load_config()
        file_path = config["service_three"]["file_path"]
        sheet = config["service_three"]["sheet_name"]
        df = pd.read_excel(file_path, sheet_name=sheet)
    except Exception:
        log_error("loading config or reading Excel file")
        return
    
    # === Process data ===
    try:
        df_trim = df[['TPID', 'TopParent', 'FiscalDate', 'ServiceLevel2', 'Acr']].copy()
        df_trim['FiscalDate'] = pd.to_datetime(df_trim['FiscalDate'])
        latest_date = df_trim['FiscalDate'].max()
        x = 30
        x_days_ago = latest_date - pd.Timedelta(days=x)
        df_trim = df_trim[df_trim['FiscalDate'] >= x_days_ago].copy()
        df_aggregated = df_trim.groupby(['TPID', "TopParent", 'FiscalDate', 'ServiceLevel2'])['Acr'].sum().reset_index()
        df_aggregated = df_aggregated.groupby(['TPID', 'FiscalDate'], group_keys=False).apply(calculate_total_usage).reset_index(drop=True)
    except Exception:
        log_error("processing and aggregating data")
        return

    # === Flag anomalies ===
    try:
        log_print("Flagging anomalies...")
        df_anomalies = flag_anomalies(df_aggregated)
        log_print("Getting instances of anomalies...")
        df_anomalies_final = get_anomalous_instances(df_anomalies)
    except Exception:
        log_error("flagging or extracting anomalies")
        return

    # === Count directions ===
    try:
        grouped = df_anomalies_final.groupby(['TopParent', 'ServiceLevel2'])
        direction_counts = df_anomalies_final[df_anomalies_final['anomaly']].groupby("ServiceLevel2")['anomaly_direction'].apply(lambda x: x.value_counts().idxmax())
        increase_services = direction_counts[direction_counts == 'increase']
        decrease_services = direction_counts[direction_counts == 'decrease']
        increase_count = len(increase_services)
        decrease_count = len(decrease_services)
    except Exception:
        log_error("counting anomaly directions")
        return

    # === Summary report ===
    try:
        direction_service_company_counts = {}
        for direction in ['increase', 'decrease']:
            df_dir = df_anomalies[df_anomalies['anomaly_direction'] == direction]
            if not df_dir.empty:
                service_company_pairs = df_dir[['TopParent', 'ServiceLevel2']].drop_duplicates()
                service_counts = service_company_pairs.groupby('ServiceLevel2')['TopParent'].nunique()
                max_count = service_counts.max()
                top_services = service_counts[service_counts == max_count].index.tolist()
                direction_service_company_counts[direction] = (max_count, top_services)
    except Exception:
        log_error("building direction_service_company_counts summary")
        return

    # === Save to Excel ===
    try:
        log_print("\nSaving flagged anomalous services to Excel...")
        true_file_name = config["service_three"]["file_path"].split("/")[-1].split(".")[0]
        if not df_anomalies_final.empty:
            df_sorted = df_anomalies_final.sort_values(by=['TopParent', 'ServiceLevel2', 'FiscalDate'])
            output_file_path = f'outputs/anomaly_detection/anomalous_services{true_file_name}.xlsx'
            df_sorted.to_excel(output_file_path, index=False)
            log_print(f"Flagged anomalous services saved to {output_file_path}, sorted by Company, Service, and Date.")
        else:
            log_print("No flagged anomalous services found to save.")
    except Exception:
        log_error("saving anomalies to Excel")
        return

    # === Summary stats for HTML ===
    try:
        summary_start = df_aggregated['FiscalDate'].min().strftime('%B %d, %Y')
        summary_end = df_aggregated['FiscalDate'].max().strftime('%B %d, %Y')
        total_companies = df_aggregated['TopParent'].nunique()
        total_anomalous_services = df_anomalies_final.groupby(['TopParent', 'ServiceLevel2']).ngroups
        increasing_anomalies = df_anomalies_final[df_anomalies_final['anomaly_direction'] == 'increase']
        increase_count = increasing_anomalies.groupby(['TopParent', 'ServiceLevel2']).ngroups
        decreasing_anomalies = df_anomalies_final[df_anomalies_final['anomaly_direction'] == 'decrease']
        decrease_count = decreasing_anomalies.groupby(['TopParent', 'ServiceLevel2']).ngroups
        direction_service_company_counts = {}
        for direction in ['increase', 'decrease']:
            df_dir = df_anomalies[df_anomalies['anomaly_direction'] == direction]
            if not df_dir.empty:
                service_company_pairs = df_dir[['TopParent', 'ServiceLevel2']].drop_duplicates()
                service_counts = service_company_pairs.groupby('ServiceLevel2')['TopParent'].nunique()
                max_count = service_counts.max()
                top_services = service_counts[service_counts == max_count].index.tolist()
                direction_service_company_counts[direction] = (max_count, top_services)
        company_anomaly_counts = df_anomalies_final.groupby('TopParent')['ServiceLevel2'].nunique()
        top_affected_companies = company_anomaly_counts.sort_values(ascending=False).head(3)
        total_usage_per_service = df_aggregated[df_aggregated['ServiceLevel2'] != 'Total Usage'].groupby('ServiceLevel2')['Acr'].sum()
    except Exception:
        log_error("generating summary stats for HTML")
        return

    # === Generate charts ===
    try:
        log_print("Generating flags per service chart...")
        image_base64_flags_per_service = generate_flags_per_service_chart(df_anomalies_final)
        log_print("Generating anomaly trend chart...")
        image_base64_anomaly_trend = generate_anomaly_trend_chart(df_anomalies_final)
        log_print("Generating usage pie chart...")
        image_base64_usage_pie = generate_usage_pie_chart(total_usage_per_service)
    except Exception:
        log_error("generating charts")
        return

    # === Generate plots over time ===
    try:
        plot_data = []
        true_file_name = config["service_three"]["file_path"].split("/")[-1].split(".")[0]
        output_dir = f'outputs/anomaly_detection/anomaly_plots({true_file_name})'
        os.makedirs(output_dir, exist_ok=True)

        grouped = df_anomalies_final.groupby(['TopParent', 'ServiceLevel2'])
        log_print("Generating plots acr over time...")
        for (company, service), group in grouped:
            plot_title = f"Acr over Time for {company} - {service}"
            file_name = f"{company.replace(' ', '_')}_{service.replace(' ', '_')}.png"
            save_path = os.path.join(output_dir, file_name)
            plot_acr_with_outliers(group['FiscalDate'], group['Acr'], group['anomaly'], plot_title, save_path)
            image_path_abs = os.path.abspath(save_path)
            median_acr = group['Acr'].median()
            plot_data.append({
                'path': image_path_abs,
                'company_service': f"{company} - {service}",
                'median_acr': median_acr
            })
        plot_data_sorted_company = sorted(plot_data, key=lambda item: item['company_service'])
        plot_data_sorted_acr = sorted(plot_data, key=lambda item: item['median_acr'], reverse=True)
    except Exception:
        log_error("plotting acr over time")
        return

    # === Generate HTML report ===
    try:
        log_print("Generating HTML report...")
        template_path = "html_files/s4_anomaly_report.html"
        env = Environment(loader=FileSystemLoader(os.path.dirname(template_path)))
        env.filters['tojson'] = tojson_filter 
        template = env.get_template(os.path.basename(template_path))

        log_print("Rendering HTML report...")
        html_content = template.render(
            report_title="Anomalous Service Report",
            report_heading="Anomalous Service Plots",
            summary_start=summary_start,
            summary_end=summary_end,
            total_companies=total_companies,
            total_anomalous_services=total_anomalous_services,
            increase_count=increase_count,
            decrease_count=decrease_count,
            direction_service_company_counts=direction_service_company_counts,
            top_affected_companies=top_affected_companies,
            flags_per_service_chart=image_base64_flags_per_service,
            anomaly_trend_chart=image_base64_anomaly_trend,
            plot_data_company=plot_data_sorted_company,
            plot_data_acr=plot_data_sorted_acr,
            sort_key="company",
            usage_pie_chart=image_base64_usage_pie
        )

        log_print("Saving HTML report...")
        html_file_path = f'outputs/anomaly_detection/anomaly_plots({true_file_name}).html'
        with open(html_file_path, 'w', encoding='utf-8') as f:
            f.write(html_content)

        log_print(f"\nPlots embedded in HTML file: {html_file_path}")
        webbrowser.open('file://' + os.path.abspath(html_file_path))
        
    except Exception:
        log_error("generating or saving HTML report")
        return