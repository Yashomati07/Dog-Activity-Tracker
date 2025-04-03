#include "TimeManager.h"
#include <WiFi.h>

const char* ssid = "your_wifi_ssid";// you have to put your own wifi credentials to connect it to ESP if you are using hardware 
const char* password = "your_wifi_password";

void TimeManager::begin() {
  // you have to add this part if you are using hardware components and want to connect wifi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi!");// up to here

    configTime(19800, 0, "pool.ntp.org");
}

void TimeManager::updateTime() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
    }
}

uint32_t TimeManager::getEpochTime() {
    return time(nullptr);
}
