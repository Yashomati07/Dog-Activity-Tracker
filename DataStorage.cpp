#include "DataStorage.h"

bool DataStorage::begin() {
    if (!LittleFS.begin()) {
        Serial.println("Failed to mount LittleFS");
        return false;
    }
    Serial.println("LittleFS mounted successfully");
    return true;
}

bool DataStorage::saveActivityData(const ActivityData& data) {
    String filename = "/data/" + String(data.timestamp) + ".dat";// you have to add the file path here 
    File file = LittleFS.open(filename, "w");
    if (!file) {
        Serial.println("Failed to open file for writing");
        return false;
    }

    file.write((const uint8_t*)&data, sizeof(data));
    file.close();
    return true;
}

bool DataStorage::readActivityData(uint32_t timestamp, ActivityData& data) {
    String filename = "/data/" + String(timestamp) + ".dat";
    File file = LittleFS.open(filename, "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return false;
    }

    file.readBytes((char*)&data, sizeof(data));
    file.close();
    return true;
}
