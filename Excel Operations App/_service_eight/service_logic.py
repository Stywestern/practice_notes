import pandas as pd

from _config.settings import load_config, save_config
from _utils.functions import open_file

def service_merge() -> pd.DataFrame:
    """Merges Excel files based on selected columns."""
    config = load_config()

    file_paths = config["service_eight"]["file_paths"]
    sheet_names = config["service_eight"]["sheet_names"]
    merging_columns = config["service_eight"]["merging_columns"]

    merged_df = None

    def get_ordinal(n: int) -> str:
        """Returns the ordinal suffix for a number (e.g., 1st, 2nd, 3rd)."""
        if 10 <= n <= 20:
            return "th"
        else:
            return {1: "st", 2: "nd", 3: "rd"}.get(n % 10, "th")

    def get_ordinal_word(n: int) -> str:
        """Returns the ordinal word (e.g., first, second, third)."""
        ordinals = {1: "first", 2: "second", 3: "third"}
        return ordinals.get(n, f"{n}{get_ordinal(n)}")

    for i, file_path in enumerate(file_paths):
        sheet_name = sheet_names[i]
        merging_column = merging_columns[i]

        try:
            df = pd.read_excel(file_path, sheet_name=sheet_name, engine='openpyxl')

            if merging_column not in df.columns:
                print(f"Warning: Column '{merging_column}' not found in '{file_path}' sheet '{sheet_name}'. Skipping.")
                continue

            df[merging_column] = df[merging_column].astype(str).fillna('')

            if merged_df is None:
                merged_df = df.rename(columns={merging_column: 'merge_key'})
            else:
                # Reset column_counts for each merge
                column_counts = {}

                merged_df = pd.merge(merged_df, df.rename(columns={merging_column: 'merge_key'}), on='merge_key', how='outer', suffixes=('', f"_{get_ordinal_word(i + 1)}"))

                # Rename duplicate columns
                new_columns = []
                for col in merged_df.columns:
                    if col not in column_counts:
                        column_counts[col] = 1
                        new_columns.append(col)
                    else:
                        new_columns.append(f"{col}_{get_ordinal_word(column_counts[col])}")
                        column_counts[col] += 1
                merged_df.columns = new_columns

        except Exception as e:
            print(f"Error merging '{file_path}' sheet '{sheet_name}': {e}")

    print("\nMerging completed.")
    return merged_df
    
    
def save_to_excel(merged_df: pd.DataFrame) -> None:
    """Trims the DataFrame and saves it as an Excel file with an information sheet."""
    config = load_config()
    selected_columns = config["service_eight"]["selected_columns"]
    file_paths = config["service_eight"]["file_paths"]
    sheet_names = config["service_eight"]["sheet_names"]

    file_names = "_".join(file_path.split("/")[-1].split(".")[0] for file_path in file_paths)
    filepath = f"outputs/merged_files/{file_names}.xlsx"

    if merged_df is not None:
        try:
            trimmed_df = merged_df[selected_columns]

            if filepath:
                with pd.ExcelWriter(filepath, engine='openpyxl') as writer:
                    trimmed_df.to_excel(writer, sheet_name='Data', index=False)

                    # Create information DataFrame
                    info_data = {
                        "Source File": [file_path.split("/")[-1] for file_path in file_paths],
                        "Sheet Name": sheet_names,
                        "Order": [f"{i + 1}" for i in range(len(file_paths))]
                    }
                    info_df = pd.DataFrame(info_data)
                    info_df.to_excel(writer, sheet_name='Information', index=False)

                print(f"DataFrame saved to: {filepath}")

        except KeyError as e:
            print(f"Error: Column '{e}' not found in DataFrame.")
        except Exception as e:
            print(f"Error saving DataFrame: {e}")
            
    # Try to open the saved file
    open_file(filepath)