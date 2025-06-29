import pandas as pd

from _config.settings import load_config
from _utils.functions import auto_header_finder, clean_sheet_name, open_file


def analyse() -> None:
    
    ####### Load Data ########
    print("\n\nLoading data...")
    config = load_config()
    file1_data = config["service_one"]["file1"]
    file2_data = config["service_one"]["file2"]

    #### Load 1st Excel File ####
    first_header_row = auto_header_finder(file1_data)
    excel1 = pd.read_excel(file1_data["file_path"], sheet_name=file1_data["sheet_name"], header=first_header_row)

    #### Load 2nd Excel File ####
    second_header_row = auto_header_finder(file2_data)
    excel2 = pd.read_excel(file2_data["file_path"], sheet_name=file2_data["sheet_name"], header=second_header_row)

    ### Create trimmed versions of the dataframes
    columns_to_pull1 = [file1_data["unique_id_column"], file1_data["forecast_column"], "Subregion"] + file1_data["extra_columns"]
    excel1_trim = excel1[columns_to_pull1]

    columns_to_pull2 = [file2_data["unique_id_column"], file2_data["forecast_column"]]
    excel2_trim = excel2[columns_to_pull2]

    # Process the columns and values
    print("Processing...")
    excel2_trim = excel2_trim.rename(columns={
        file2_data["forecast_column"] : file1_data["forecast_column"],
        file2_data["unique_id_column"] : file1_data["unique_id_column"]
    })

    if file1_data["unique_id_column"] == "TopParent":
        excel1_trim[file1_data["unique_id_column"]] = excel1_trim[file1_data["unique_id_column"] ].str.strip().str.lower()
        excel2_trim[file2_data["unique_id_column"]] = excel2_trim[file2_data["unique_id_column"] ].str.strip().str.lower()
        
    excel2_trim = excel2_trim.merge(excel1_trim[[file1_data["unique_id_column"], "Subregion"] + file1_data["extra_columns"]], on=file1_data["unique_id_column"], how='left')
    excel2_trim = excel2_trim[excel1_trim.columns]
    
    excel1_trim = excel1_trim.copy()
    excel2_trim = excel2_trim.copy()

    excel1_trim.loc[:, file1_data["forecast_column"]] = pd.to_numeric(excel1_trim[file1_data["forecast_column"]], errors='coerce')
    excel2_trim.loc[:, file1_data["forecast_column"]] = pd.to_numeric(excel2_trim[file1_data["forecast_column"]], errors='coerce')

    excel1_trim.loc[:, 'Source'] = 'source1'
    excel2_trim.loc[:, 'Source'] = 'source2'

    ####### Merge Data ########
    combined_df = pd.concat([excel1_trim, excel2_trim], ignore_index=True)

    ###### Create Pivot Table #########

    pivot_table = combined_df.pivot_table(
    index=[file1_data["unique_id_column"], "Subregion"] + list(file1_data["extra_columns"]),  # Rows for each dataset
    columns='Source',  # Columns for each dataset
    values= file1_data["forecast_column"],  # Values to compare
    aggfunc='first'    # Use the first occurrence if duplicates exist
    )

    ###### Create Analysis Columns #########
    pivot_table['Difference (source1 - source2)'] = pivot_table['source1'] - pivot_table['source2']

    # Add similarity percentage column
    pivot_table['Similarity % (source1 - source2)'] = pivot_table.apply(
        lambda row: (1 - abs(row['source1'] - row['source2']) / row['source1']) * 100
        if row['source1'] != 0 else 0,
        axis=1
    )

    pivot_table = pivot_table.sort_values(
    by=['Difference (source1 - source2)', 'Similarity % (source1 - source2)'],
    ascending=[False, True]
    )

    ##### Process Pivot Table #####

    filtered_pivot_table = pivot_table[pivot_table["Difference (source1 - source2)"] >= 1000]

    filtered_pivot_table = filtered_pivot_table.sort_values(
        by=['Difference (source1 - source2)', 'Similarity % (source1 - source2)'],
        ascending=[True, False]
    )

    ###### To Excel ######
    
    file_name1 = file1_data["file_path"].split('/')[-1].split('.')[0]
    file_name2 = file2_data["file_path"].split('/')[-1].split('.')[0]
    output_file_name = f"outputs/forecast_comparisons/forecast_comparison({file_name1}+{file_name2}).xlsx"
    
    with pd.ExcelWriter(output_file_name, engine="openpyxl") as writer:
        # Create the information to be written in the "Info" sheet
        info_data = {
            "Information": ["Data from Source 1:", f"{file_name1}", "Data from Source 2:", f"{file_name2}"],
        }

        info_df = pd.DataFrame(info_data)
        info_df.to_excel(writer, sheet_name="Info", index=False)
        
        # Write the whole pivot table
        pivot_table.to_excel(writer, sheet_name="All Data", index=True)
        
        # Iterate through unique Subregions
        for subregion in pivot_table.index.get_level_values("Subregion").unique():
            clean_subregion = clean_sheet_name(subregion)
            subregion_data = pivot_table.xs(subregion, level="Subregion")
            subregion_data.to_excel(writer, sheet_name=clean_subregion, index=True)

    print(f"Data exported successfully to {output_file_name}")
    
    # Try to open the file
    open_file(output_file_name)