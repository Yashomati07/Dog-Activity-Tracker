#ifndef SIMULATEDQMI8658_H
#define SIMULATEDQMI8658_H

#include <Arduino.h>

struct IMUdata {
    float x, y, z;
};

class SimulatedQMI8658 {
private:
    bool motionDetected;
    void (*wakeupCallback)();

public:
    SimulatedQMI8658();
    bool begin();
    bool readFromFifo(IMUdata* acc, int accCount, IMUdata* gyr, int gyrCount);
    void configWakeOnMotion();
    void setWakeupMotionEventCallBack(void (*callback)());
    void simulateMotion();
};

#endif
