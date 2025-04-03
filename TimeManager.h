#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <Arduino.h>
#include <WiFi.h>
#include <time.h>

class TimeManager {
public:
    void begin();
    void updateTime();
    uint32_t getEpochTime();
};

#endif
