import requests
import time
from datetime import datetime

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
        ip_address = entry["field4"]

        print(f"\n📡 Latest ThingSpeak Entry:")
        print(f"🕒 Timestamp      : {time_str}")
        print(f"💧 Humidity       : {humidity} %")
        print(f"🌡️ Temperature    : {temperature} °C")
        print(f"🌱 Soil Moisture  : {soil_moisture}")
        print(f"🌐 Device IP      : {ip_address}\n")
    except Exception as e:
        print(f"Error formatting entry: {e}")


def send_command(esp32_ip, command):
    url = f"http://{esp32_ip}/command?command={command}"
    try:
        response = requests.get(url)
        response.raise_for_status()
        print(response.text)
    except requests.exceptions.RequestException as e:
        print(f"Error sending command: {e}")


if __name__ == "__main__":
    channel_id = "2887470"  # Your ThingSpeak channel ID
    read_api_key = "7W07WL45AH35JO6K"  # Your ThingSpeak read API key
    interval = 10  # Seconds between data retrievals

    print(f"🔄 Retrieving latest data from ThingSpeak channel {channel_id} every {interval} seconds...")
    print("Press Ctrl+C to stop.")

    try:
        while True:
            entry = get_latest_thingspeak_entry(channel_id, read_api_key)
            if entry:
                #print_nicely(entry)
                try:
                    print("Sending commands...")
                    send_command(entry["field4"], "led_on")
                    send_command(entry["field4"], "relay_off")
                    time.sleep(5)
                    send_command(entry["field4"], "led_off")
                    send_command(entry["field4"], "relay_on")
                    time.sleep(5)
                except requests.exceptions.RequestException as e:
                    print(f"Network error: {e}")
                    time.sleep(5) # wait 10 seconds, before retrying.
                except Exception as e:
                    print(f"An unexpected error occurred: {e}")
                    break # break the loop, as something unexpected happend.

            time.sleep(interval)
    except KeyboardInterrupt:
        print("\n🛑 Data retrieval stopped.")
