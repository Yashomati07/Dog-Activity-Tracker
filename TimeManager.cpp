#include "TimeManager.h"

void TimeManager::begin() {
    configTime(0, 0, "pool.ntp.org");
    delay(2000);  // Allow time for NTP sync
}

time_t TimeManager::getCurrentTime() {
    return time(nullptr);
}
