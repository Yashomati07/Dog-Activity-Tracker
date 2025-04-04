#include <Arduino.h>
#include "SimulatedQMI8658.h"
#include "TimeManager.h"
#include "ActivityClassifier.h"
#include "DataStorage.h"

// Objects for each module
SimulatedQMI8658 sensor;
TimeManager timeManager;
ActivityClassifier classifier;
DataStorage dataStorage;

void wakeUpHandler() {
    Serial.println("Motion detected!");
}

void setup() {
    Serial.begin(115200);

    // Initialize components
    if (sensor.begin()) {
        Serial.println("Sensor initialized.");
    }
    sensor.setWakeupMotionEventCallBack(wakeUpHandler);

    timeManager.begin();
    dataStorage.begin();

    Serial.println("Setup complete.");
}

void loop() {
    IMUdata acc[10], gyr[10];
    if (sensor.readFromFifo(acc, 10, gyr, 10)) {
        int activityType = classifier.classifyActivity(acc, 10);
        dataStorage.storeData(timeManager.getCurrentTime(), activityType);
    }

    // Simulate motion periodically for testing
    sensor.simulateMotion();
    delay(2000);
}
