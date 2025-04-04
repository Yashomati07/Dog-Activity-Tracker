#include <Arduino.h>
#include "SimulatedQMI8658.h"
#include "TimeManager.h"
#include "DataStorage.h"
#include "ActivityClassifier.h"

// Initialize instances
SimulatedQMI8658 imuSensor;
TimeManager timeManager;
DataStorage dataStorage;
ActivityClassifier activityClassifier;

void motionDetectedCallback() {
    Serial.println("Motion detected!");
}

void setup() {
    Serial.begin(115200);

    // Initialize sensor simulation
    if (imuSensor.begin()) {
        imuSensor.setWakeupMotionEventCallBack(motionDetectedCallback);
        Serial.println("IMU Sensor initialized.");
    }

    // Initialize time manager and sync time
    timeManager.begin();

    // Initialize data storage
    if (dataStorage.begin()) {
        Serial.println("Data storage initialized with LittleFS.");
    }

    // Initialize activity classifier
    activityClassifier.begin();
}

void loop() {
    // Simulate motion and read from the FIFO buffer
    imuSensor.simulateMotion();

    IMUdata accData[10], gyrData[10];
    imuSensor.readFromFifo(accData, 10, gyrData, 10);

    // Run activity classification
    String activity = activityClassifier.classify(accData, 10);

    // Display classified activity
    Serial.print("Activity: ");
    Serial.println(activity);

    // Save activity data
    ActivityData activityData;
    activityData.timestamp = timeManager.getEpochTime();
    if (activity == "Resting") activityData.restingDuration += 10;
    else if (activity == "Walking") activityData.walkingDuration += 10;
    else if (activity == "Running") activityData.runningDuration += 10;
    else if (activity == "Playing") activityData.playingDuration += 10;

    dataStorage.saveActivityData(activityData);

    delay(2000); // Delay to simulate interval between readings
}
