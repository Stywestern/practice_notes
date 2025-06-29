import pandas as pd
from datetime import datetime

def delete_entries_by_date(file_path: str, sheet_name: str, date_column: str, date_to_delete: str):
    """
    Loads an Excel sheet, deletes entries matching a specific date in a given column,
    and returns the modified DataFrame.

    Args:
        file_path (str): The path to the Excel file.
        sheet_name (str): The name of the sheet to load.
        date_column (str): The name of the column containing the dates.
        date_to_delete (str): The date to delete (in a format pandas can parse, e.g., 'YYYY-MM-DD').

    Returns:
        pandas.DataFrame: The DataFrame with the specified date entries removed,
                          or an error message as a string if something goes wrong.
    """
    try:
        # Load the Excel sheet into a pandas DataFrame
        df = pd.read_excel(file_path, sheet_name=sheet_name, engine='openpyxl')

        # Convert the date column to datetime objects for accurate comparison
        df[date_column] = pd.to_datetime(df[date_column])

        # Convert the date to delete to a datetime object for comparison
        date_to_delete_dt = pd.to_datetime(date_to_delete)

        # Create a boolean mask to identify rows where the date column matches the date to delete
        mask = df[date_column] == date_to_delete_dt

        # Invert the mask to keep rows that do NOT match the date to delete
        df_filtered = df[~mask]

        return df_filtered

    except FileNotFoundError:
        return f"Error: File not found at '{file_path}'"
    except KeyError:
        return f"Error: Column '{date_column}' not found in the sheet '{sheet_name}'"
    except ValueError:
        return f"Error: Could not parse the date '{date_to_delete}'. Please use a valid format (e.g., YYYY-MM-DD)."
    except Exception as e:
        return f"An unexpected error occurred: {e}"

if __name__ == '__main__':
    # Example usage:
    file_path = r"C:\Users\v-kcantimur\Downloads\ACR-Report-C2025-04-21-151704.xlsx"  # Replace with your file path
    sheet_name = "ACRs Daily SL2📅"               # Replace with your sheet name
    date_column = "FiscalDate"          # Replace with the name of your date column
    date_to_delete = "2025-04-19"       # Replace with the date you want to delete

    modified_df = delete_entries_by_date(file_path, sheet_name, date_column, date_to_delete)
    
    output_file_path = r"C:\Users\v-kcantimur\Downloads\SL2_modified.xlsx"

    if isinstance(modified_df, pd.DataFrame):
        # Save the modified DataFrame to a new Excel file
        try:
            modified_df.to_excel(output_file_path, sheet_name=sheet_name, index=False)
            print(f"\nModified data saved to '{output_file_path}'")
        except Exception as e:
            print(f"Error saving the modified DataFrame: {e}")
    else:
        print(modified_df)