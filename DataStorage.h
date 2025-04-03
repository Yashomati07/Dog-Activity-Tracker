#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <Arduino.h>
#include <LittleFS.h>

struct ActivityData {
    uint32_t timestamp;
    uint16_t restingDuration;
    uint16_t walkingDuration;
    uint16_t runningDuration;
    uint16_t playingDuration;
};

class DataStorage {
public:
    bool begin();
    bool saveActivityData(const ActivityData& data);
    bool readActivityData(uint32_t timestamp, ActivityData& data);
};

#endif
