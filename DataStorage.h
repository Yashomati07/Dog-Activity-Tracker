#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <LittleFS.h>

class DataStorage {
public:
    bool begin();
    void storeData(uint32_t timestamp, int activityType);
};

#endif
