#ifndef ACTIVITY_CLASSIFIER_H
#define ACTIVITY_CLASSIFIER_H

#include "SimulatedQMI8658.h"

class ActivityClassifier {
public:
    int classifyActivity(IMUdata* data, int count);
};

#endif
