#include "DataStorage.h"

bool DataStorage::begin() {
    return LittleFS.begin();
}

void DataStorage::storeData(uint32_t timestamp, int activityType) {
    String filename = "/data/" + String(timestamp / 86400) + ".dat";
    File file = LittleFS.open(filename, FILE_APPEND);

    if (file) {
        file.write((uint8_t*)&timestamp, sizeof(timestamp));
        file.write((uint8_t*)&activityType, sizeof(activityType));
        file.close();
    }
}
