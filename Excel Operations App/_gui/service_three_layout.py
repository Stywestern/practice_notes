import customtkinter as ctk
from tkinter import ttk
from tkinter import filedialog
import pandas as pd
import logging

from _config.settings import load_config, save_config
from _utils.functions import clear_frame
from _gui.monitor import setup_monitor
from _service_three.service_logic import analyse
from _service_three.service_constants import entry_message

# Retrieve the logger instance
logger = logging.getLogger('AppLogger')
logger.info('Entered to service three (Minimal Layout)')


def select_file(button: ctk.CTkButton, dropdown: ttk.Combobox) -> None:
    """Allows the user to select the report file."""
    config = load_config()
    file_path = filedialog.askopenfilename(title="Select File")
    if file_path:
        excel_file = pd.ExcelFile(file_path, engine='openpyxl')
        sheet_names_list = excel_file.sheet_names
        
        dropdown.configure(values=sheet_names_list)
        dropdown.set("Select sheet")

        file_name = file_path.split("/")[-1]
        button.configure(text=f"Selected file: {file_name}")
        print(f"Usage report file set to: {file_name}")

        config["service_three"]["file_path"] = file_path
        save_config(config)


def handle_sheet_selection(selected_sheet: str) -> None:
    """Handles the selection of the sheet and saves it to config."""
    print(f"Selected sheet for usage analysis: {selected_sheet}\n")
    config = load_config()
    config["service_three"]["sheet_name"] = selected_sheet
    save_config(config)


def setup_service_three(left_frame: ctk.CTkFrame, right_frame: ctk.CTkFrame) -> None:
    """Sets up the layout for the Usage Change Analysis service."""
    clear_frame(left_frame)
    clear_frame(right_frame)
    
    # Main menu button
    from _gui.layout import setup_default_layout
    switch_button = ctk.CTkButton(left_frame, text="Main menu", command=lambda: setup_default_layout(left_frame, right_frame))
    switch_button.grid(row=0, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Setup the monitor
    setup_monitor(right_frame)
    print(entry_message)
    
    # File selection
    file_button = ctk.CTkButton(left_frame, text="Select Usage Report File\nNo file selected",
                                 command=lambda: select_file(file_button, sheet_dropdown))
    file_button.grid(row=1, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Sheet selection
    sheet_dropdown = ctk.CTkComboBox(left_frame, values=[], state="readonly",
                                     command=handle_sheet_selection)
    sheet_dropdown.grid(row=2, column=0, columnspan=2, pady=10, padx=10, sticky="ew")
    
    # Analysis button
    analysis_button = ctk.CTkButton(left_frame, text="Analyse Report", command=analyse)
    analysis_button.grid(row=3, column=0, columnspan=2, pady=10, padx=10, sticky="ew")

    # Update column/row configurations
    left_frame.grid_columnconfigure(0, weight=1)
    for i in range(5):
        left_frame.grid_rowconfigure(i, weight=0)
    