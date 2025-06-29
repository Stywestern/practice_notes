import customtkinter as ctk
import sys

class MonitorRedirector:
    def __init__(self, output_widget):
        self.output_widget = output_widget
    
    def write(self, text):
        self.output_widget.insert('end', text)
        self.output_widget.see('end')


def setup_monitor(right_frame: ctk.CTkFrame) -> None:
    monitor = ctk.CTkTextbox(master=right_frame, height=400, width=400, wrap="word")
    monitor.pack(padx=10, pady=10, fill="both", expand=True)
    stdout_redirector = MonitorRedirector(monitor)
    sys.stdout = stdout_redirector 
    sys.stderr = stdout_redirector