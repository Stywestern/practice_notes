## Directory Structure

├── _config / config module
├── _gui / gui module
├── _service_five / service_five module
├── _service_four / service_four module
├── _service_one / service_one module
├── _service_six / service_six module
├── _service_three / service_three module
├── _service_two / service_two module
├── _utils / utils module
├── config / holds the config.json and id_to_company.csv
├── inputs
	├── files_to_analyse_forecasts
	├── files_to_check_changes
	├── files_to_compare_forecasts
	├── files_to_show_milestones
	├── files_to_show_trends
	└── files_to_transform_marina
└── outputs
	├── compare_changes
	├── excel_marina_transformed
	├── forecast_analysis
	├── forecast_comparisons
	├── html_reports
   		└── images
	├── milestone_comparisons
	└── trend_changes

## Module Overview

- **_config:** Stores the config json file path and logic, includes:
  - settings.py:
    - load_config: loads the json from the path or creates a new one
    - save_config: writes the active dictionary in runtime into json
    - terminate_program: stores the closing protocols
    - clear_service_one_config: deletes the stored data at the end of the program
    - pretty_print_config: printing scheme for config data
- **_utils:** Stores important constants and helper functions, includes:
  - constants_n_variables.py: contains reusable messages to print and dictionaries to be used in layouts or logics for the services.
  - functions.py:
    - clear_frame: clean widgets and stdouts
    - extract_date: get the datetime from excel file name given the expected format
    - clean_sheet_name: makes the custom sheet names appropriate for excel
    - auto_header_finder: finds the ideal header for the excel sheet given a column name
    - dolarize: formats the value into US dollars.
- **_gui:** Stores reusable layouts and classes for UI elements, includes:
  - monitor.py:
    - MonitorRedirector: a class to redirect stdout to app interface
    - setup_monitor: sets up the monitor for interfaces
  - layout.py:
    - show_loading_screen: creates a custom loading screen on startup
    - show_loading_screen_in: creates a loading screen for tasks
    - setup_default_layout: creates main menu widgets
  - service_one_layout.py:
    - select_file: file selection logic for service one
    - handle_drowdown_selection: contains the logics for dropdown widgets
    - populate_column_dropdowns: populates dropdowns based on previous selections
    - select_extra_columns: logic for selecting extra columns from a single dropdown
    - clear_extra_columns: deselects all selected extra column
    - confirm_inputs: saves the selections and print them onto the monitor
    - setup_service_one: contains the general layout of service one interface
  - service_two_layout:
    - select_file: file selection logic for service two
    - handle_drowdown_selection: contains the logics for dropdown widgets
    - setup_service_two: contains the general layout of service two interface
  - service_three_layout:
    - select_file: file selection logic for service three
    - handle_drowdown_selection: contains the logics for dropdown widgets
    - setup_service_two: contains the general layout of service three interface
  - service_four_layout:
    - select_file: file selection logic for service four
    - handle_drowdown_selection: contains the logics for dropdown widgets
    - setup_service_two: contains the general layout of service four interface
  - service_five_layout:
    - select_file: file selection logic for service five
    - handle_drowdown_selection: contains the logics for dropdown widgets
    - setup_service_two: contains the general layout of service five interface
  - service_six_layout:
    - select_file: file selection logic for service six
    - handle_drowdown_selection: contains the logics for dropdown widgets
    - setup_service_two: contains the general layout of service six interface
  - service_seven_layout:
    - select_file: file selection logic for service seven
    - confirm_sheet_selection: contains the logic for sheet assignments
    - setup_service_seven: contains the general layout of service seven interface
  - service_eight_layout:
    - select_files: file selection logic for service eight
    - create_column_dropdowns: sets up dropdowns for the user to select ID columns
    - display_column_checkboxes: creates checkboxes for merged_excel's columns
    - get_selected_checkboxes: retrieves the column selections made by the user
    - setup_service_eight: contains the general layout of service eight interface
- _service_one:
  - service_constants: includes the messages printed on the monitor when the user enters the service
  - service_logic:
    - analyse: this service compares two ACR files and creates a sheet that showcase the differences between their forecast values for companies
- _service_two:
  - service_constants: includes the messages printed on the monitor when the user enters the service
  - service_logic:
    - compare: this service compares two similarly constructed excel files and creates an excel file that shows the differences between the two, formats the changed cells into "old_value -> new_value" style and paints the changed cells to designated highlighting format
- _service_three:
  - service_constants: includes the messages printed on the monitor when the user enters the service and the coloring for the highlighted cells in the output
  - service_logic:
    - clean_dataframes: takes the old and new dataframes and handles the missing values, as well as trimming the months that is not relevant for the analysis
    - merge_dataframes: merges the old and the new and trims based on subregion if specified
    - change_date_format: from detailed datetime to "Month Year"
    - show: filters the columns of dataframes which include information about milestone commitments
    - show_workload: adds columns that shows which services are utilized more
    - show_workload_def: like show_workload but includes special services (?)
    - show_change: shows the milestone commitment differences in old and new
    - show_new_records: shows the new entries on milestone commitment columns
    - uncommited_q1: shows the milestones that haven't been locked
    - analyse: this service takes two excel files that hold milestone information and creates an excel file which has many sheets that analyse the commitments.
- _service_four:
  - service_constants: includes the messages printed on the monitor when the user enters the service
  - service_logic:
    - change_date_format: from detailed datetime to "Month Year"
    - clean_dataframes: takes the old and new dataframes and handles the missing values, as well as trimming the months that is not relevant for the analysis
    - plot_milestone_status: creates plots from the dataframes
    - image_to_data_uri: changes the image path into an html path
    - merge_dataframes: merges the old and the new and trims based on subregion if specified
    - show_workload: adds columns that shows which services are utilized more
    - show_new_records: shows the new entries on milestone commitment columns
    - analyse: this service takes two excel files that hold milestone information and creates charts and detailed html reports containing the information.
- _service_five:
  - service_constants: includes the messages printed on the monitor when the user enters the service
  - service_logic:
    - process_dataframe: cleans the dataframe and creates custom columns for later comparison
    - analyse: this service uses acr excel files to create an excel that shows the spending trends
- _service_six:
  - service_constants: includes the messages printed on the monitor when the user enters the service
  - service_logic:
    - remove_outliers_iqr: cleans the dataframe using inter quantile range method
    - remove_outliers_zscore: cleans the dataframe using z_score method
    - is_outside_20_percent_area: helper function to calculate quantile position
    - expand_dataframe: standardizes dataframes to include certain columns
    - analyse: this service uses an acr excel file and an archive file to create an analysis of forecast data contained on that files.
- _service_seven:
  - Under construction
- _service_eight:
  - service_constants: includes the messages printed on the monitor when the user enters the service
  - service_logic:
    - service_merge: merges the files using the ID columns specified for merging. It labels the columns that have same names as Col, Col_second, Col_third.
    - save_to_excel: saves the excel file in following sheets; info_sheet, merged_excel
