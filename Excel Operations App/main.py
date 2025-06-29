import sys
import customtkinter as ctk
import warnings
import openpyxl
import matplotlib
import logging

from _config.settings import load_config, terminate_program
from _gui.layout import setup_default_layout

# Suppress the specific warning from some libraries
warnings.filterwarnings("ignore", category=UserWarning, module="openpyxl", message="Workbook contains no default style")
warnings.simplefilter(action='ignore', category=FutureWarning)

######### Initial Setup #########

### Load configuration
config = load_config()

original_stdout = sys.stdout
original_stderr = sys.stderr

### Configure logging
with open("outputs/app.log", "w"):
    pass  # Opening in 'w' mode clears the file

logging.basicConfig(
    filename="outputs/app.log",
    level=logging.DEBUG,  # Set log level to capture DEBUG, INFO, etc.
    format="%(asctime)s - %(name)s - %(levelname)s - %(filename)s:%(lineno)d - %(funcName)s() - %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S"  # Custom date format (optional)
)

# Create a logger instance (usually named the same as the module, here 'AppLogger')
logger = logging.getLogger('AppLogger')
logger.info("Logging system initialized")

######### Load and initialize the app ########
app = ctk.CTk()
app.title("Azure Pipeline Velocity Tracking")
app.geometry("920x520")
app.iconbitmap(config["microsoft_icon"])
ctk.set_appearance_mode("dark")

######### Create frames and monitors
left_frame = ctk.CTkFrame(master=app, width=400, height=800)
left_frame.grid(row=0, column=0, sticky="nsew", padx=10, pady=2)
left_frame.grid_rowconfigure(0, weight=1)  # This makes the first row inside left_frame expandable
left_frame.grid_columnconfigure(0, weight=1)  # This makes the first column inside left_frame expandable

app.grid_rowconfigure(0, weight=1)
app.grid_columnconfigure(0, weight=1)

# Add scrollable frame using grid instead of pack
scroll_frame = ctk.CTkScrollableFrame(master=left_frame)
scroll_frame.grid(row=0, column=0, sticky="nsew")  # Use grid, and sticky to fill the frame
left_frame.grid_rowconfigure(0, weight=1)  # Make sure row and column are configured to allow resizing
left_frame.grid_columnconfigure(0, weight=1)

right_frame = ctk.CTkFrame(master=app, width=650, height=800)
right_frame.grid(row=0, column=1, sticky="nsew", padx=10, pady=7)
right_frame.grid_rowconfigure(0, weight=1)
right_frame.grid_columnconfigure(0, weight=1)

footer_label = ctk.CTkLabel(
        master=app,
        text="Azure Helper Services - Beta Version",
        font=("Arial", 10)
    )
footer_label.grid(row=1, column=0, columnspan=2, pady=10)

# Ensure the right frame takes full width/height
app.grid_rowconfigure(0, weight=1)  # Allow the first row to expand
app.grid_columnconfigure(0, weight=1)  # Allow the first column to expand
app.grid_columnconfigure(1, weight=1)  # Allow the second column (right_frame) to expand

######## Create initial setup
setup_default_layout(scroll_frame, right_frame)

###### Closing protocol 
def on_closing() -> None:
    try:
        terminate_program()
    finally:
        sys.stdout = original_stdout
        sys.stderr = original_stderr
        app.quit()  # Gracefully close the app

# Bind the custom closing event
app.protocol("WM_DELETE_WINDOW", on_closing)

###### Start the app #####
app.mainloop()



