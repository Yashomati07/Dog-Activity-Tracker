#ifndef SIMULATED_QMI8658_H
#define SIMULATED_QMI8658_H

#include <Arduino.h>

struct IMUdata {
    float x, y, z;
};

class SimulatedQMI8658 {
private:
    bool motionDetected;
    void (*wakeupCallback)();

public:
    SimulatedQMI8658() : motionDetected(false), wakeupCallback(nullptr) {}
    bool begin();
    bool readFromFifo(IMUdata* acc, int accCount, IMUdata* gyr, int gyrCount);
    void configWakeOnMotion();
    void setWakeupMotionEventCallBack(void (*callback)());
    void simulateMotion();
};

#endif
