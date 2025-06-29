import customtkinter as ctk
from tkinter import ttk
from tkinter import filedialog
import pandas as pd
import logging

from _config.settings import load_config, save_config
from _utils.functions import clear_frame
from _gui.monitor import setup_monitor
from _service_two.service_logic import compare
from _service_two.service_constants import entry_message

# Retrieve the logger instance defined in main.py
logger = logging.getLogger('AppLogger')
logger.info('Entered to service two')


def select_file(button: ctk.CTkButton, dropdown: ttk.Combobox, file_index: int) -> None:
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

            config["service_two"][f"file{file_index}"]["file_path"] = file_path

        save_config(config)


checkbox_vars = {}  # Global variable to store checkbox states
def handle_dropdown_selection(selected_sheet: str, file_index: int, 
                              unique_key_dropdown: ctk.CTkComboBox, checkbox_frame: ctk.CTkFrame) -> None:
    
    print(f"File {file_index} selected sheet is set to: {selected_sheet}\n")

    config = load_config()
    config["service_two"][f"file{file_index}"]["sheet_name"] = selected_sheet
    save_config(config)

    file_path = config["service_two"][f"file{file_index}"]["file_path"]
    df = pd.read_excel(file_path, sheet_name=selected_sheet, engine='openpyxl')
    
    column_list = df.columns.tolist()

    if file_index == 1:
        # Fill unique key dropdown
        unique_key_dropdown.configure(values=column_list)
        unique_key_dropdown.set("Select Unique Key")

        # Fill checkboxes
        for widget in checkbox_frame.winfo_children():
            widget.destroy()
        checkbox_vars.clear()
        
        # Add "Select All" button
        def select_all():
            for var in checkbox_vars.values():
                var.set(True)

        select_all_button = ctk.CTkButton(checkbox_frame, text="Select All", command=select_all)
        select_all_button.pack(anchor='w')

        for col in column_list:
            var = ctk.BooleanVar()
            cb = ctk.CTkCheckBox(checkbox_frame, text=col, variable=var)
            cb.pack(anchor='w')
            checkbox_vars[col] = var
            

def setup_service_two(left_frame: ctk.CTkFrame, right_frame: ctk.CTkFrame) -> None:
    # Clear frames
    clear_frame(left_frame)
    clear_frame(right_frame)

    # Main menu button
    from _gui.layout import setup_default_layout
    switch_button = ctk.CTkButton(left_frame, text="Main menu", command=lambda: setup_default_layout(left_frame, right_frame))
    switch_button.grid(row=0, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Ensure the right frame has proper monitor setup
    setup_monitor(right_frame)
    print(entry_message)

    # Unique key selection
    unique_key_label = ctk.CTkLabel(left_frame, text="Select Unique Key")
    unique_key_label.grid(row=5, column=0, padx=10, sticky="w")

    unique_key_dropdown = ctk.CTkComboBox(left_frame, state="readonly")
    unique_key_dropdown.grid(row=5, column=1, padx=10, sticky="ew")

    # Save selection
    def on_unique_key_selected(selected):
        config = load_config()
        config["service_two"]["unique_id_column"] = selected
        save_config(config)
        print(f"Unique key set to: {selected}")

    unique_key_dropdown.configure(command=on_unique_key_selected)

    # Frame for checkboxes
    checkbox_frame = ctk.CTkFrame(left_frame)
    checkbox_frame.grid(row=6, column=0, columnspan=2, padx=10, pady=5, sticky="ew")

    def save_checked_columns():
        selected_columns = [col for col, var in checkbox_vars.items() if var.get()]
        config = load_config()
        config["service_two"]["compare_columns"] = selected_columns
        save_config(config)
        print(f"Columns selected for comparison: {selected_columns}")

    save_button = ctk.CTkButton(left_frame, text="Save Selected Columns", command=save_checked_columns)
    save_button.grid(row=7, column=0, columnspan=2, padx=10, pady=5, sticky="ew")
    
    # File selection button for excel file 1
    file_button1 = ctk.CTkButton(left_frame, text="Select File 1\nNo file selected", 
                command=lambda: select_file(file_button1, dropdown1, 1))
    file_button1.grid(row=1, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    dropdown1 = ctk.CTkComboBox(left_frame, values=[], state="readonly", 
                command=lambda selected: handle_dropdown_selection(selected, 1, unique_key_dropdown, checkbox_frame))
    dropdown1.grid(row=2, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # File selection button for excel file 2
    file_button2 = ctk.CTkButton(left_frame, text="Select File 2\nNo file selected", 
                command=lambda: select_file(file_button2, dropdown2, 2))
    file_button2.grid(row=3, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    dropdown2 = ctk.CTkComboBox(left_frame, values=[], state="readonly", 
                command=lambda selected: handle_dropdown_selection(selected, 2, unique_key_dropdown, checkbox_frame))
    dropdown2.grid(row=4, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Analyse button
    analyse_button = ctk.CTkButton(left_frame, text="Compare", command=compare)
    analyse_button.grid(row=8, column=0, columnspan=2, pady=20, padx=10, sticky="ew")
    
    # Update column/row configurations in the left frame to resize properly
    for row in range(7):
        left_frame.grid_rowconfigure(row, weight=0)

    # Adjust column configuration to fix the empty space issue
    left_frame.grid_columnconfigure(0, weight=3)  # Give weight to the label column
    left_frame.grid_columnconfigure(1, weight=4)  # Give weight to the entry column so it doesn't stretch too much