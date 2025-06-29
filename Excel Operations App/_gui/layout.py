import customtkinter as ctk
import tkinter as tk
from tkinter import ttk

from _utils.functions import clear_frame
from _utils.constants_n_variables import welcome_message
from _gui.monitor import setup_monitor

def show_loading_screen(app: ctk.CTk) -> ctk.CTkToplevel:
    icon_path = "images/Microsoft.ico"
    
    loading_screen = ctk.CTkToplevel(app)
    loading_screen.title("Session started")
    loading_screen.geometry("300x100")
    loading_screen.iconbitmap(icon_path)
    loading_label = ctk.CTkLabel(loading_screen, text="Session started, please wait...", font=("Arial", 14))
    loading_label.pack(pady=20)

    return loading_screen

def show_loading_screen_in() -> ctk.CTkToplevel:
    def cancel_action() -> None:
        print("Process cancelled")
        loading_screen.destroy()

    loading_screen = tk.Toplevel()
    loading_screen.title("Loading")
    loading_screen.geometry("680x200")
    loading_screen.configure(bg='#333333')
    label = tk.Label(loading_screen, text="Processing, please wait...", font=("Helvetica", 20), fg="white", bg="#333333")
    loading_screen.iconbitmap("images/Microsoft.ico")
    label.pack(pady=20)

    style = ttk.Style()
    style.theme_use('clam')
    style.configure("TProgressbar", thickness=30, troughcolor='#333333', background='gray')

    progress_bar = ttk.Progressbar(loading_screen, mode='indeterminate', style="TProgressbar")
    progress_bar.pack(expand=True, pady=20, padx=20, fill='x')
    progress_bar.start()

    cancel_button = tk.Button(loading_screen, text="Stop everything!", command=cancel_action, font=("Helvetica", 18), bg="gray", fg="white")
    cancel_button.pack(pady=10)
    loading_screen.iconbitmap("images/Microsoft.ico")
    
    return loading_screen


def setup_default_layout(left_frame: ctk.CTkFrame, right_frame: ctk.CTkFrame) -> None:
    # Delayed import to avoid circular imports
    from _gui.service_one_layout import setup_service_one
    from _gui.service_two_layout import setup_service_two
    from _gui.service_eight_layout import setup_service_eight
    from _gui.service_three_layout import setup_service_three
    
    # Clear the frames 
    clear_frame(left_frame)
    clear_frame(right_frame)
    
    ###### Define the structure of the layout
    
    # Monitor setup
    setup_monitor(right_frame)
    print(welcome_message)

    # Option to switch to Service 8
    service8_button = ctk.CTkButton(master=left_frame, text="Merge Excels", command=lambda: setup_service_eight(left_frame, right_frame))
    service8_button.pack(padx=10, pady=10)
    
    # Option to switch to Service 1
    service1_button = ctk.CTkButton(master=left_frame, text="Forecast Comparison", command=lambda: setup_service_one(left_frame, right_frame))
    service1_button.pack(padx=10, pady=10)
    
    # Option to switch to Service 2
    service2_button = ctk.CTkButton(master=left_frame, text="Detect Changes", command=lambda: setup_service_two(left_frame, right_frame))
    service2_button.pack(padx=10, pady=10)
    
    # Option to switch to Service 3
    service3_button = ctk.CTkButton(master=left_frame, text="Service Usage Report", command=lambda: setup_service_three(left_frame, right_frame))
    service3_button.pack(padx=10, pady=10)

    

