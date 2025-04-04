# Dog-Activity-Tracker-project-using-ESP32

A project that monitors a dog's activity using an ESP32 microcontroller, a simulated accelerometer/gyroscope, and LittleFS for data storage. The tracker categorizes activities (Resting, Walking, Running, and Playing) and stores the data for easy syncing with a mobile app.

---

##  Project Overview

The Dog Activity Tracker uses:

- **Simulated Accelerometer**: Emulates a QMI8658 sensor to provide motion data.
- **Activity Classification**: Simple threshold-based system to identify activity types.
- **Data Storage**: Uses LittleFS to log activity in 10-minute intervals.
- **Time Management**: Maintains time with ESP32's RTC and syncs via NTP when Wi-Fi is available.

---

##  Requirements

### Hardware:
- ESP32-S3 microcontroller  
- QMI8658 Accelerometer + Gyroscope module  
- LiPo Battery + Charging Circuit  
- LCD Screen (for output visualization)  

### Libraries / Dependencies
- ESP32 Arduino Core (v2.0.14)
- LittleFS (filesystem library)
- BLE (for mobile sync - optional)
- ArduinoOTA (for over-the-air updates - optional)

### Future Improvements
- Integrate real TensorFlow Lite model for smarter activity recognition
- BLE support for syncing with a mobile app
- Real sensor integration for real-time tracking
- Cloud sync functionality

---

##  Setup

1.**Clone Repository**
   ```bash
   git clone https://github.com/Yashomati07/Dog-Activity-Tracker-project-using-ESP32.git
   cd Dog-Activity-Tracker-project-using-ESP32
