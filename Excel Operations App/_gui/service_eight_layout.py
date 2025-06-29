import customtkinter as ctk
from tkinter import filedialog
import pandas as pd
import logging

from _config.settings import load_config, save_config
from _utils.functions import clear_frame
from _gui.monitor import setup_monitor
from _service_eight.service_logic import service_merge, save_to_excel
from _service_eight.service_constants import entry_message

# Retrieve the logger instance defined in main.py
logger = logging.getLogger('AppLogger')
logger.info('Entered to service two')


def select_files(button: ctk.CTkButton, frame: ctk.CTkFrame) -> None:
    config = load_config()

    selected_files = filedialog.askopenfilenames(title="Select Excel files", filetypes=[("Excel files", "*.xlsx")])

    if selected_files:
        config["service_eight"]["file_paths"] = selected_files
        # Initialize sheet_names with empty strings to ensure correct indexing
        config["service_eight"]["sheet_names"] = [""] * len(selected_files)

        for index, file_path in enumerate(selected_files):
            excel_file = pd.ExcelFile(file_path, engine='openpyxl')
            sheet_names = excel_file.sheet_names

            label = ctk.CTkLabel(frame, text=f"Sheet {index + 1}:")
            label.grid(row=index, column=0, padx=5, pady=5, sticky='w')

            var = ctk.StringVar()
            dropdown = ctk.CTkComboBox(frame, values=sheet_names, variable=var)
            dropdown.grid(row=index, column=1, padx=5, pady=5, sticky='ew')

            def on_sheet_select(choice, index=index):
                print(f"Selected sheet {index + 1}: {choice}")
                config["service_eight"]["sheet_names"][index] = choice # Update using index
                save_config(config)

            dropdown.configure(command=on_sheet_select)

        button.configure(text=f"Selected files: {len(selected_files)} files")
        save_config(config)
        
        print(f"Selected files:")
        for file in selected_files:
            print(f" - {file}")
        print()
        
def create_column_dropdowns(frame: ctk.CTkFrame) -> None:
    config = load_config()
    row_correcter = len(config["service_eight"]["file_paths"])

    # Initialize merging_columns with empty strings to ensure correct indexing
    config["service_eight"]["merging_columns"] = [""] * len(config["service_eight"]["file_paths"])

    for index, file_path in enumerate(config["service_eight"]["file_paths"]):
        sheet_name = config["service_eight"]["sheet_names"][index]

        try:
            df = pd.read_excel(file_path, sheet_name=sheet_name, engine='openpyxl')
            column_names = df.columns.tolist()

            column_label = ctk.CTkLabel(frame, text=f"Column {index + 1}:")
            column_label.grid(row=index + row_correcter, column=0, padx=5, pady=5, sticky='w')

            column_var = ctk.StringVar()
            column_dropdown = ctk.CTkComboBox(frame, values=column_names, variable=column_var)
            column_dropdown.grid(row=index + row_correcter, column=1, padx=5, pady=5, sticky='ew')

            def on_column_select(choice: str, index: int=index):
                print(f"Selected sheet {index + 1} column: {choice}")
                config["service_eight"]["merging_columns"][index] = choice # Update using index
                save_config(config)

            column_dropdown.configure(command=on_column_select)

        except Exception as e:
            print(f"Error reading sheet or columns: {e}")


def display_column_checkboxes(frame: ctk.CTkFrame) -> None:
    """Displays checkboxes for the merged DataFrame's columns."""
    merged_columns = service_merge().columns.tolist()
    
    for col in merged_columns:
        checkbox = ctk.CTkCheckBox(frame, text=col)
        checkbox.pack(padx=10, pady=5, anchor='w')


def get_selected_checkboxes(checkbox_frame: ctk.CTkFrame) -> None:
    """Retrieves the selected checkboxes from the frame."""
    config = load_config()
    selected_columns = []
    for widget in checkbox_frame.winfo_children():
        if isinstance(widget, ctk.CTkCheckBox):
            if widget.get():  
                selected_columns.append(widget.cget("text")) 
                
    config["service_eight"]["selected_columns"] = selected_columns
    save_config(config)
    
    print("\nSelected columns:")
    for column in selected_columns:
        print(f"-{column}")
    save_to_excel(service_merge())


def setup_service_eight(left_frame: ctk.CTkFrame, right_frame: ctk.CTkFrame) -> None:
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
    
    ### Widgets
    
    ## Frames
    dropdown_frame = ctk.CTkScrollableFrame(left_frame, height=200)
    dropdown_frame.grid(row=3, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    checkbox_frame = ctk.CTkScrollableFrame(left_frame, height=200)
    checkbox_frame.grid(row=5, column=0, columnspan=2, pady=10, padx=10, sticky="ew")
    
    ## Buttons
    file_button = ctk.CTkButton(left_frame, text="Select Files\nNo files selected", command=lambda: select_files(file_button, dropdown_frame))
    file_button.grid(row=1, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    column_button = ctk.CTkButton(left_frame, text="Select Columns", state="normal", command=lambda: create_column_dropdowns(dropdown_frame))
    column_button.grid(row=2, column=0, columnspan=2, pady=10, padx=10, sticky="ew")
    
    merge_button = ctk.CTkButton(left_frame, text="Confirm & Merge", command=lambda: display_column_checkboxes(checkbox_frame))
    merge_button.grid(row=4, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    confirm_button = ctk.CTkButton(left_frame, text="Confirm & Save", command=lambda: get_selected_checkboxes(checkbox_frame))
    confirm_button.grid(row=6, column=0, columnspan=2, pady=10, padx=10, sticky="ew")
    
    left_frame.grid_columnconfigure(0, weight=1)
    left_frame.grid_columnconfigure(1, weight=1) 
