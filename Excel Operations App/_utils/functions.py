from datetime import datetime
import customtkinter as ctk
import pandas as pd
import locale
import os

from _config.settings import save_config, load_config


### Clears the widgets and outputs from a frame
def clear_frame(frame: ctk.CTkFrame) -> None:
    for widget in frame.winfo_children():
        widget.destroy()


### Extracts the date from the filename
def extract_date(filename: str) -> datetime:
    # If the file in question has the name format %2024-12-18-090340.xlsx
    # Remove the ".xlsx" extension and parse the date part
    
    date_str = filename.replace(".xlsx", "")
    try:
        return datetime.strptime(date_str, '%Y%m%d_%H%M')
    except ValueError:
        return None
    
    
### Function to change the sheet name into something acceptable by excel
def clean_sheet_name(string: str) -> str:
        invalid_chars = ['/', '\\', '?', '*', '[', ']', ':']
        for char in invalid_chars:
            string = string.replace(char, '_') 
        return string   
    

### Function to find the appropriate header row of the Excel file
def auto_header_finder(file_data: dict, column_name="TPID") -> int:
    excel1 = pd.read_excel(file_data["file_path"], sheet_name=file_data["sheet_name"], header=None)

    # Loop through the rows to find the ID column
    header_row = None
    for i, row in excel1.iterrows():
        if column_name in row.values:
            header_row = i  # Store the index of the header row
            break
        else:
            header_row = 0

    # If a header row was found, reload the Excel file with the correct header
    if header_row is not None:
        return header_row
    else:
        raise ValueError("TPID column not found")
    

### Transforms the values on the column into us dollars format
def dolarize(serie: pd.Series) -> list:
    locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')
    myvar = list(serie)
    for i in range(len(myvar)):
        amount = myvar[i]
        formatted_amount = locale.currency(amount, grouping=True).split('.')[0]
        if amount < 0:
            formatted_amount = f"-${formatted_amount[2:]}"  # Remove parentheses and add a minus sign
        myvar[i] = formatted_amount
    return myvar


def open_file(output_path: str) -> None:
    try:
        abs_path = os.path.abspath(output_path) #makes absolute path
        if os.name == 'nt':  # Windows
            os.startfile(abs_path)
        elif os.name == 'posix':  # macOS or Linux
            subprocess.run(['open', abs_path])  # macOS
            # subprocess.run(['xdg-open', abs_path]) #linux
        else:
            print(f"Cannot automatically open file on this operating system.")
    except Exception as e:
        print(f"Error opening the output file: {e}")
        
        
        