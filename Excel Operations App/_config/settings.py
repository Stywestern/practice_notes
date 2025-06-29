import os
import json
import logging

CONFIG_FILE = "config/config.json"
logger = logging.getLogger('AppLogger')

def load_config() -> dict:
    dir_path = os.path.dirname(CONFIG_FILE)
    
    # Create the directory if it doesn't exist
    if dir_path and not os.path.exists(dir_path):
        os.makedirs(dir_path)  

    # Check if the config file exists and load it
    if os.path.exists(CONFIG_FILE):
        with open(CONFIG_FILE, 'r') as f:
            logger.info("Config file loaded successfully.")
            return json.load(f)
            

    # Return an empty dictionary if the file doesn't exist
    return {}


def save_config(config: dict) -> None:
    with open(CONFIG_FILE, 'w') as f:
        logger.info("Config file saved successfully.")
        json.dump(config, f)
        

def clear_service_one_config() -> None:
    config = load_config()

    # Clear values under the "service_one" key for both file1 and file2
    config["service_one"]["file1"] = {
        "file_path": "",
        "sheet_name": "",
        "unique_id_column": "",
        "forecast_column": "",
        "extra_columns": []
    }
    config["service_one"]["file2"] = {
        "file_path": "",
        "sheet_name": "",
        "unique_id_column": "",
        "forecast_column": ""
    }

    logger.info("Config for service_one cleared")
    
    # Save the updated config
    save_config(config)


def clear_service_two_config() -> None:
    config = load_config()

    # Clear values under the "service_one" key for both file1 and file2
    config["service_one"]["file1"] = {
        "file_path": "",
        "sheet_name": "",
    }
    config["service_one"]["file2"] = {
        "file_path": "",
        "sheet_name": "",
    }
    config["service_two"]["unique_id_column"] = ""
    config["service_two"]["compare_columns"] = []

    logger.info("Config for service_one cleared")
    
    # Save the updated config
    save_config(config)

def clear_service_eight_config() -> None:
    config = load_config()

    # Clear values under the "service_one" key for both file1 and file2
    config["service_eight"]["file_paths"] = []
    config["service_eight"]["sheet_names"] = []
    config["service_eight"]["merging_columns"] = []
    config["service_eight"]["selected_columns"] = []
    

    logger.info("Config for service_eight cleared")
    
    # Save the updated config
    save_config(config)


def terminate_program() -> None:
    clear_service_one_config()
    clear_service_two_config()
    clear_service_eight_config()


def pretty_print_config(service: str) -> None:
    config = load_config()
    if service == "service_one":
        for file_key, file_data in config["service_one"].items():
            print(f"\n##### {file_key.capitalize()} #####")
            print(f"File Path: {file_data['file_path']}")
            print(f"Sheet Name: {file_data['sheet_name']}")
            print(f"Unique ID Column: {file_data['unique_id_column']}")
            print(f"Forecast Column: {file_data['forecast_column']}")

            if file_data.get('extra_columns'):
                print(f"Extra Columns: {', '.join(file_data['extra_columns']) if file_data['extra_columns'] else 'None'}")
