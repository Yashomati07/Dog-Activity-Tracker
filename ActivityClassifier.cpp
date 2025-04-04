#include "ActivityClassifier.h"

int ActivityClassifier::classifyActivity(IMUdata* data, int count) {
    float avgZ = 0;
    for (int i = 0; i < count; i++) {
        avgZ += abs(data[i].z);
    }
    avgZ /= count;

    if (avgZ < 0.5) return 0;  // Resting
    if (avgZ < 1.5) return 1;  // Walking
    if (avgZ < 3.0) return 2;  // Running
    return 3;                  // Playing
}
