import requests
import time
from datetime import datetime
import pickle
import numpy as np


def get_latest_thingspeak_entry(channel_id, read_api_key):
    """Retrieves the latest entry from ThingSpeak."""
    try:
        url = f"https://api.thingspeak.com/channels/{channel_id}/feeds.json?api_key={read_api_key}&results=1"
        response = requests.get(url, timeout=5)
        response.raise_for_status()
        data = response.json()
        if "feeds" in data and len(data["feeds"]) > 0:
            return data["feeds"][0]  # Return the latest entry
        return None
    except requests.exceptions.RequestException as e:
        print(f"Error retrieving data from ThingSpeak: {e}")
        return None


def print_nicely(entry):
    """Prints the ThingSpeak entry in a readable format."""
    try:
        time_str = entry["created_at"]
        humidity = entry["field1"]
        temperature = entry["field2"]
        soil_moisture = entry["field3"]

        print(f"\n📡 Latest ThingSpeak Entry:")
        print(f"🕒 Timestamp      : {time_str}")
        print(f"💧 Humidity       : {humidity} %")
        print(f"🌡️ Temperature    : {temperature} °C")
        print(f"🌱 Soil Moisture  : {soil_moisture}")
    except Exception as e:
        print(f"Error formatting entry: {e}")


def clear_talkback_commands(talkback_id, api_key):
    url = f"https://api.thingspeak.com/talkbacks/{talkback_id}/commands.json"
    response = requests.delete(url, params={"api_key": api_key})
    if response.status_code == 200:
        print("✅ TalkBack queue cleared.")
    else:
        print("❌ Failed to clear queue:", response.text)


def send_talkback_command(talkback_id, api_key, command_str):
    clear_talkback_commands(talkback_id, api_key)
    url = f"https://api.thingspeak.com/talkbacks/{talkback_id}/commands.json"
    response = requests.post(url, data={
        "api_key": api_key,
        "command_string": command_str
    })
    if response.status_code == 200:
        print(f"✅ Command sent: {command_str}")
    else:
        print(f"❌ Failed to send command: {response.text}")


def convert_4095_to_1023(value):
    return float((value / 4095) * 1023)


if __name__ == "__main__":
    PUMP_current = 250 / 20 # 250ml / 20sn

    channel_id = "2887470"  # Your ThingSpeak channel ID
    read_api_key = "7W07WL45AH35JO6K"  # Your ThingSpeak read API key

    talkback_id = "54690"
    talkback_api_key = "M19L0E6ZL4XDUVD9" 

    interval = 1  # Seconds between data retrievals

    print(f"🔄 Retrieving latest data from ThingSpeak channel {channel_id} every {interval} seconds...")
    print("Press Ctrl+C to stop.")

    # Load the model
    with open("xgb_watering_model.pkl", "rb") as file:
        model = pickle.load(file)
    
    ##### Main Loop ####
    try:
        while True:
            entry = get_latest_thingspeak_entry(channel_id, read_api_key)

            if entry:
                if entry["field1"] == None or entry["field2"] == None or entry["field3"] == None:
                    print("⚠️ Incomplete data in ThingSpeak entry. Skipping this loop.")
                    time.sleep(interval)
                    continue  # Skip this loop iteration
                
                # hum, temp, soil mois
                input_features = [float(entry["field1"]), float(entry["field2"]), convert_4095_to_1023(float(entry["field3"]))]
                input_array = np.array(input_features).reshape(1, -1)

                print(input_features)

                prediction = model.predict(input_array)
                print("Prediction:", prediction[0]) 

                if prediction == 0:
                    try:
                        print("Sending commands...")
                        send_talkback_command(talkback_id, talkback_api_key, "relay_off")
                    except requests.exceptions.RequestException as e:
                        print(f"Network error: {e}")
                        time.sleep(5)
                    except Exception as e:
                        print(f"An unexpected error occurred: {e}")
                        break
                else:
                    try:
                        print("Sending commands...")
                        send_talkback_command(talkback_id, talkback_api_key, "relay_on")
                    except requests.exceptions.RequestException as e:
                        print(f"Network error: {e}")
                        time.sleep(5)
                    except Exception as e:
                        print(f"An unexpected error occurred: {e}")
                        break


            time.sleep(interval)

    except KeyboardInterrupt:
        print("\n🛑 Data retrieval stopped.")
