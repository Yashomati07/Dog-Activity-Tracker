#include <Arduino.h>

// Simulated IMU data structure
struct IMUdata {
    float x, y, z;
};

// Simulated QMI8658 Class
class SimulatedQMI8658 {
private:
    bool motionDetected;
    void (*wakeupCallback)();

public:
    SimulatedQMI8658() : motionDetected(false), wakeupCallback(nullptr) {}

    // Initialize sensor (simulation)
    bool begin() {
        Serial.println("Simulated QMI8658 Initialized.");
        return true;
    }

    // Generate random IMU data
    bool readFromFifo(IMUdata* acc, int accCount, IMUdata* gyr, int gyrCount) {
        for (int i = 0; i < accCount; i++) {
            acc[i].x = random(-32768, 32767) / 1000.0;
            acc[i].y = random(-32768, 32767) / 1000.0;
            acc[i].z = random(-32768, 32767) / 1000.0;
        }
        for (int i = 0; i < gyrCount; i++) {
            gyr[i].x = random(-32768, 32767) / 100.0;
            gyr[i].y = random(-32768, 32767) / 100.0;
            gyr[i].z = random(-32768, 32767) / 100.0;
        }
        return true;
    }

    // Configure Wake-on-Motion
    void configWakeOnMotion() {
        Serial.println("Wake-on-Motion Configured.");
    }

    // Set wake-up callback
    void setWakeupMotionEventCallBack(void (*callback)()) {
        wakeupCallback = callback;
    }

    // Simulate motion detection
    void simulateMotion() {
        if (random(100) < 5 && !motionDetected) { // 5% chance of motion
            motionDetected = true;
            if (wakeupCallback) wakeupCallback();
        } else {
            motionDetected = false;
        }
    }
};

// Create a sensor instance
SimulatedQMI8658 imu;

void motionDetectedCallback() {
    Serial.println("Motion Detected! Waking up...");
}

void setup() {
    Serial.begin(115200);
    imu.begin();
    imu.configWakeOnMotion();
    imu.setWakeupMotionEventCallBack(motionDetectedCallback);
}

void loop() {
    IMUdata acc[10], gyr[10];
    imu.readFromFifo(acc, 10, gyr, 10);
    imu.simulateMotion();  // Simulate motion event
    delay(500);
}
