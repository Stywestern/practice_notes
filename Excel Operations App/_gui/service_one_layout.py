### Forecast comparison service layout ###

import customtkinter as ctk
from tkinter import filedialog
import pandas as pd
import logging

from _config.settings import load_config, save_config, pretty_print_config
from _utils.functions import clear_frame, auto_header_finder
from _gui.monitor import setup_monitor
from _service_one.service_logic import analyse
from _service_one.service_constants import entry_message

# Retrieve the logger instance defined in main.py
logger = logging.getLogger('AppLogger')
logger.info('Entered to service one')


def select_file(button: ctk.CTkButton, dropdown: ctk.CTkComboBox, file_index: int) -> None:
    config = load_config()
    file_path = filedialog.askopenfilename(title=f"Select Excel file {file_index}")
    
    if file_path:
        # Read the excel file and get sheet names
        excel_file = pd.ExcelFile(file_path, engine='openpyxl')
        sheet_names_list = excel_file.sheet_names

        # Update the dropdown menu with sheet names
        dropdown.configure(values=sheet_names_list)
        dropdown.set("Select sheet")

        file_name = file_path.split("/")[-1]
        button.configure(text=f"Selected file: {file_name}")
        print(f"File {file_index} is set to: {file_name}")

        config["service_one"][f"file{file_index}"]["file_path"] = file_path

    save_config(config)


def handle_dropdown_selection(selected_sheet: str, file_index: int, unique_id_dropdown: ctk.CTkComboBox, 
                              forecast_dropdown: ctk.CTkComboBox, extra_columns_dropdown: ctk.CTkComboBox):
    config = load_config()
    
    # Store the selected sheet name
    config["service_one"][f"file{file_index}"]["sheet_name"] = selected_sheet
    save_config(config)
    print(f"File {file_index} selected sheet is set to: {selected_sheet}")

    # Load the selected file's sheet
    file_data = config["service_one"][f"file{file_index}"]

    if file_data:
        df = pd.read_excel(file_data["file_path"], sheet_name=selected_sheet, header=None)
        header_row = auto_header_finder(file_data)
        df = pd.read_excel(file_data["file_path"], sheet_name=selected_sheet, header=header_row)

        # Populate column dropdowns with headers, including extra columns dropdown
        filtered_columns = populate_column_dropdowns(df, unique_id_dropdown, forecast_dropdown, extra_columns_dropdown, file_index)

        # Adjust the extra_columns_dropdown to allow selections from filtered columns
        extra_columns_dropdown.configure(values=filtered_columns)


def populate_column_dropdowns(df: pd.DataFrame, unique_id_dropdown: ctk.CTkComboBox, forecast_dropdown: ctk.CTkComboBox, 
                              extra_columns_dropdown: ctk.CTkComboBox, file_index: int) -> list:
    config = load_config()
    
    # Get the column names (headers)
    col_names = sorted(list(df.columns))
    excluded_columns = ["Subregion"]
    
    # Get the already selected extra columns from the config
    selected_extra_columns = config["service_one"][f"file{file_index}"].get("extra_columns", [])

    # Filter out the "Subregion" column and selected extra columns
    filtered_columns = [col for col in col_names if col not in excluded_columns and col not in selected_extra_columns]

    # Update the dropdowns with filtered column headers
    unique_id_dropdown.configure(values=filtered_columns)
    forecast_dropdown.configure(values=filtered_columns)
    
    return filtered_columns  # Return filtered columns for extra column handling


def select_extra_columns(extra_column: str, extra_columns_dropdown: ctk.CTkComboBox, file_index: int=1) -> None:
    config = load_config()

    if extra_column:
        # Get already selected extra columns
        selected_extra_columns = config["service_one"][f"file{file_index}"].get("extra_columns", [])

        if extra_column not in selected_extra_columns:
            selected_extra_columns.append(extra_column)  # Add the new selection to the list

            # Update the config with the new list
            config["service_one"][f"file{file_index}"]["extra_columns"] = selected_extra_columns
            save_config(config)
            
            print(f"Selected Extra Columns: {', '.join(selected_extra_columns) if selected_extra_columns else 'None'}")

    # Filter out selected extra columns from dropdown options
    current_values = list(extra_columns_dropdown.cget('values'))
    new_values = [col for col in current_values if col != extra_column]
    extra_columns_dropdown.configure(values=new_values)

    # Clear the dropdown for further selections
    extra_columns_dropdown.set("")


def clear_extra_columns(file_index: int=1) -> None:
    config = load_config()

    # Clear the extra columns for the specified file in the config
    config["service_one"][f"file{file_index}"]["extra_columns"] = []
    save_config(config)

    print("Cleared all selected extra columns")

def confirm_inputs(unique_id_dropdown1: ctk.CTkComboBox, forecast_dropdown1: ctk.CTkComboBox, 
                   unique_id_dropdown2: ctk.CTkComboBox, forecast_dropdown2: ctk.CTkComboBox):
    
    config = load_config()

    file1_unique_id = unique_id_dropdown1.get()
    file1_forecast = forecast_dropdown1.get()

    file2_unique_id = unique_id_dropdown2.get()
    file2_forecast = forecast_dropdown2.get()

    config["service_one"]["file1"]["unique_id_column"] = file1_unique_id
    config["service_one"]["file1"]["forecast_column"] = file1_forecast

    config["service_one"]["file2"]["unique_id_column"] = file2_unique_id
    config["service_one"]["file2"]["forecast_column"] = file2_forecast

    save_config(config)
    logger.info("User inputs confirmed and stored:")
    print("User inputs confirmed and stored:")
    pretty_print_config("service_one")


def setup_service_one(left_frame: ctk.CTkFrame, right_frame: ctk.CTkFrame) -> None:
    # Clear frames
    clear_frame(left_frame)
    clear_frame(right_frame)

    # Main menu button
    from _gui.layout import setup_default_layout
    switch_button = ctk.CTkButton(left_frame, text="Main menu", command=lambda: setup_default_layout(left_frame, right_frame))
    switch_button.grid(row=0, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Setup the monitor
    setup_monitor(right_frame)
    print(entry_message)

    # File selection button for excel file 1
    file_button1 = ctk.CTkButton(left_frame, text="Select File 1\nNo file selected", 
                command=lambda: select_file(file_button1, dropdown1, 1))
    file_button1.grid(row=1, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    dropdown1 = ctk.CTkComboBox(left_frame, values=[], state="readonly", 
                command=lambda selected: handle_dropdown_selection(selected, 1, unique_id_dropdown1, forecast_dropdown1, extra_columns_dropdown1))
    dropdown1.grid(row=2, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Unique ID column dropdown for File 1
    unique_id_label1 = ctk.CTkLabel(left_frame, text="ID column for File 1:")
    unique_id_label1.grid(row=3, column=0, padx=5, pady=5, sticky="w")
    unique_id_dropdown1 = ctk.CTkComboBox(left_frame, state="readonly")
    unique_id_dropdown1.grid(row=3, column=1, padx=5, pady=5, sticky="ew")
    
    # Forecast column dropdown for File 1
    forecast_label1 = ctk.CTkLabel(left_frame, text="Forecast column for File 1:")
    forecast_label1.grid(row=4, column=0, padx=5, pady=5, sticky="w")
    forecast_dropdown1 = ctk.CTkComboBox(left_frame, state="readonly")
    forecast_dropdown1.grid(row=4, column=1, padx=5, pady=5, sticky="ew")

    # Extra columns dropdown for File 1 
    extra_columns_label1 = ctk.CTkLabel(left_frame, text="Extra columns for File 1:")
    extra_columns_label1.grid(row=5, column=0, padx=5, pady=5, sticky="w")
    extra_columns_dropdown1 = ctk.CTkComboBox(left_frame, values=[], state="readonly", 
                command=lambda selected: select_extra_columns(selected, extra_columns_dropdown1))
    extra_columns_dropdown1.grid(row=5, column=1, padx=5, pady=5, sticky="ew")

    # Button to clear extra column selections
    clear_button1 = ctk.CTkButton(left_frame, text="Clear Extra Columns", command=clear_extra_columns)
    clear_button1.grid(row=6, column=0, columnspan=2, padx=5, pady=5, sticky="ew")

    # File selection button for excel file 2
    file_button2 = ctk.CTkButton(left_frame, text="Select File 2\nNo file selected", 
                command=lambda: select_file(file_button2, dropdown2, 2))
    file_button2.grid(row=7, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    dropdown2 = ctk.CTkComboBox(left_frame, values=[], state="readonly", 
                command=lambda selected: handle_dropdown_selection(selected, 2, unique_id_dropdown2, forecast_dropdown2, extra_columns_dropdown1))
    dropdown2.grid(row=8, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Unique ID column dropdown for File 2
    unique_id_label2 = ctk.CTkLabel(left_frame, text="ID column for File 2:")
    unique_id_label2.grid(row=9, column=0, padx=5, pady=5, sticky="w")
    unique_id_dropdown2 = ctk.CTkComboBox(left_frame, state="readonly")
    unique_id_dropdown2.grid(row=9, column=1, padx=5, pady=5, sticky="ew")
    
    # Forecast column dropdown for File 2
    forecast_label2 = ctk.CTkLabel(left_frame, text="Forecast column for File 2:")
    forecast_label2.grid(row=10, column=0, padx=5, pady=5, sticky="w")
    forecast_dropdown2 = ctk.CTkComboBox(left_frame, state="readonly")
    forecast_dropdown2.grid(row=10, column=1, padx=5, pady=5, sticky="ew")

    # Confirm Button
    confirm_button = ctk.CTkButton(left_frame, text="Confirm Inputs", 
                command=lambda: confirm_inputs(unique_id_dropdown1, forecast_dropdown1, unique_id_dropdown2, forecast_dropdown2))
    confirm_button.grid(row=11, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Analyse button
    analyse_button = ctk.CTkButton(left_frame, text="Analyse", command=analyse)
    analyse_button.grid(row=13, column=0, columnspan=2, pady=20, padx=10, sticky="ew")
    
    # Update column/row configurations in the left frame to resize properly
    for row in range(14):
        left_frame.grid_rowconfigure(row, weight=0)

    # Adjust column configuration to fix the empty space issue
    left_frame.grid_columnconfigure(0, weight=3)  # Give weight to the label column
    left_frame.grid_columnconfigure(1, weight=4)  # Give weight to the entry column so it doesn't stretch too much

