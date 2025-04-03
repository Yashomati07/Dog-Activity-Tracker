#ifndef ACTIVITYCLASSIFIER_H
#define ACTIVITYCLASSIFIER_H

#include <Arduino.h>

class ActivityClassifier {
public:
    void begin();
    String classifyActivity(float accX, float accY, float accZ);
};

#endif
