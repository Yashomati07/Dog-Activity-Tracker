#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <Arduino.h>
#include <time.h>

class TimeManager {
public:
    void begin();
    time_t getCurrentTime();
};

#endif
