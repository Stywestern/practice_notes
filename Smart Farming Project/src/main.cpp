#include <Arduino.h>
#include <time.h>
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <HTTPClient.h> 
#include <WiFiServer.h>
#include "ThingSpeak.h"

// Time
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600 * 3; // Adjust for your timezone (Istanbul is GMT+3)
const int   daylightOffset_sec = 0;

// Wi-Fi Settings
const char* ssid = "Galaxy A53 5G 7507";
const char* password = "hwpx1270";
WiFiServer server(80);

// ThingSpeak Server Settings
WiFiClient  client;

unsigned long myChannelNumber = 2887470;
const char * myWriteAPIKey = "C72BBAEET0UFASC6";

const char* talkbackApiKey = "M19L0E6ZL4XDUVD9";
const char* talkbackId = "54690";

// Pin Definitions
const int relayPin = 26;
const int dhtPin = 23;
const int soilMoisturePin = 35;
const int ledPin = 2; 

// DHT Sensor Setup
#define DHTTYPE DHT11
DHT dht(dhtPin, DHTTYPE);

// LCD Setup
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Timing Variables
const long thingSpeakInterval = 20000; // 15 seconds in milliseconds
unsigned long previousThingSpeakMillis = 0;

static unsigned long lastTalkbackCheck = 0;
const unsigned long talkbackInterval = 20000; // Poll ThingSpeak TalkBack every 15 seconds

// Lcd Variables
unsigned long previousLcdSwitchMillis = 0;
const long lcdSwitchInterval = 4000;  // 4 seconds
int screenState = 0;

// Sensor data cache (to reuse values between LCD updates)
float cachedHumidity = 0;
float cachedTemperature = 0;
int cachedSoilMoisture = 0;

String nowAsString() {
  time_t now;
  struct tm timeinfo;
  time(&now);
  localtime_r(&now, &timeinfo);

  char buf[20];
  strftime(buf, sizeof(buf), "%H:%M:%S", &timeinfo);
  return String(buf);
}

void setup() {
  // Init monitor
  Serial.begin(115200);

  // Init time
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

  // Relay Setup
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // LOW means it is working by the way

  // DHT Setup
  dht.begin();

  // LCD Setup
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Starting...");
  lcd.display();

  lcd.setCursor(0, 1);
  lcd.print("Connecting WiFi");

  // Wifi section
  WiFi.begin(ssid, password);
  Serial.print(WiFi.status());

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    lcd.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    ThingSpeak.begin(client);
  } else {
    Serial.println("WiFi connection failed. Continuing without WiFi.");
    lcd.setCursor(0, 1);
    lcd.print("WiFi failed      ");
  }

  // Start Server
  server.begin();
  pinMode(ledPin, OUTPUT); // init LED pin
  digitalWrite(ledPin, LOW); // LED off
}


void loop() {

  if (WiFi.status() == WL_CONNECTED && millis() - lastTalkbackCheck > talkbackInterval) {
    lastTalkbackCheck = millis();
    HTTPClient http;
    String url = "https://api.thingspeak.com/talkbacks/";
    url += talkbackId;
    url += "/commands/execute?api_key=";
    url += talkbackApiKey;
  
    http.begin(url);
    int httpCode = http.GET();
  
    if (httpCode == 200) {
      String command = http.getString();
      command.trim();  // Remove newline or whitespace

      Serial.print(nowAsString());
      Serial.println(" TalkBack command received: " + command);
  
      if (command == "relay_on") {
        digitalWrite(relayPin, HIGH);
        Serial.print(nowAsString());
        Serial.println(" Relay turned ON");
      } else if (command == "relay_off") {
        digitalWrite(relayPin, LOW);
        Serial.print(nowAsString());
        Serial.println(" Relay turned OFF");
      } else if (command == "led_on") {
        digitalWrite(ledPin, HIGH);
        Serial.print(nowAsString());
        Serial.println(" LED turned ON");
      } else if (command == "led_off") {
        digitalWrite(ledPin, LOW);
        Serial.print(nowAsString());
        Serial.println(" LED turned OFF");
      } else if (command.length() > 0) {
        Serial.print(nowAsString());
        Serial.println(" Unknown command: " + command);
      } else {
        Serial.print(nowAsString());
        Serial.println(" No new commands.");
      }
  
    } else {
      Serial.print(nowAsString());
      Serial.print(" Failed to contact TalkBack. HTTP error code: ");
      Serial.println(httpCode);
    }
  
    http.end();
  }

  // Non-Blocking ThingSpeak Upload
  unsigned long currentMillis = millis();
  if (currentMillis - previousThingSpeakMillis >= thingSpeakInterval) {
    previousThingSpeakMillis = currentMillis;

    // Read Sensors and Send Data to ThingSpeak
    float humidity = dht.readHumidity();
    delay(200);
    float temperature = dht.readTemperature();
    delay(200);
    int soilMoistureValue = analogRead(soilMoisturePin);
    

    if (isnan(humidity)) {
      humidity = 0;
    }
    if (isnan(temperature)) {
      temperature = 0;
    }
    if (isnan(soilMoistureValue)) {
      soilMoistureValue = 0;
    }

    // Cache values for LCD use
    cachedHumidity = isnan(humidity) ? 0 : humidity;
    cachedTemperature = isnan(temperature) ? 0 : temperature;
    cachedSoilMoisture = soilMoistureValue;

    // Thingspeak send off
    String ipStr = WiFi.localIP().toString();

    ThingSpeak.setField(1, humidity);
    ThingSpeak.setField(2, temperature);
    ThingSpeak.setField(3, soilMoistureValue);
    int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
    if (x == 200) {
      Serial.print(nowAsString());
      Serial.println(" Channel update successful.");
    } else {
      Serial.print(nowAsString());
      Serial.println(" Problem updating channel. HTTP error code " + String(x));
    }
      
    // Serial Output
    Serial.print(nowAsString());
    Serial.print(" Humidity: ");
    Serial.print(humidity);
    Serial.print(" %, Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C, Soil Moisture: ");
    Serial.println(soilMoistureValue);

  }

  // Display Sensor Data on LCD
  if (millis() - previousLcdSwitchMillis >= lcdSwitchInterval) {
    previousLcdSwitchMillis = millis();
    screenState = (screenState + 1) % 2;  // Toggle 0 ↔ 1
  
    lcd.clear();
    if (screenState == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(cachedTemperature);
      lcd.print(" C");
  
      lcd.setCursor(0, 1);
      lcd.print("Hum: ");
      lcd.print(cachedHumidity);
      lcd.print(" %");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Soil Moisture:");
      lcd.setCursor(0, 1);
      lcd.print(cachedSoilMoisture);
    }
    lcd.display();
  }
}