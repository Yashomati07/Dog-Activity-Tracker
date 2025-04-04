# Dog-Activity-Tracker
This project is a simulated Dog Activity Tracker built on the ESP32 platform. It uses simulated accelerometer and gyroscope data to classify a dog’s activities, such as Resting, Walking, Running, and Playing. This proof-of-concept demonstrates activity classification, low-power wake-on-motion, and efficient data storage using LittleFS.

## Features
- **Simulated Motion Data**: Mimics accelerometer and gyroscope readings without physical sensors.
- **Wake-on-Motion**: ESP32 deep sleep and wake-up mechanism for power-efficient tracking.
- **Time Synchronization**: Uses NTP to keep time accurate.
- **Basic Activity Classification**: Simple activity classifier for foundational analysis.
- **Data Storage**: Logs activity data to LittleFS in structured intervals.

## Project Components
1. **Core Functionality & Sensor Simulation**: 
   - Simulates accelerometer and gyroscope data using the `SimulatedQMI8658` class.
2. **Wake-up Mechanism**: 
   - Uses deep sleep with wake-on-motion and scheduled wake-ups every 2 minutes.
3. **Time Management**: 
   - Manages time via NTP and ESP32's RTC during deep sleep.
4. **Activity Classification**:
   - Basic classifier with placeholders for TensorFlow Lite integration, pending dataset availability.
5. **Data Storage**: 
   - Stores logs in a structured format using LittleFS.

## Installation & Setup
1. **Prerequisites**: Ensure Arduino IDE is set up for ESP32 with the required libraries:
   - `ESP32 Arduino Core` (v2.0.14)
   - `LittleFS` for ESP32
   - `WiFi` for NTP sync
2. **Code Structure**: 
   - Place all `.h` and `.cpp` files in the same folder as the `.ino` file.
3. **Simulated Motion**: Modify `SimulatedQMI8658` for custom motion patterns if needed.
4. **NTP Configuration**: Customize NTP server settings in `TimeManager.cpp` if desired.

## Usage
1. Clone the repository and open the `.ino` file in Arduino IDE.
2. Upload the code to an ESP32 board (or run in simulation mode without hardware).
3. Observe activity logs and classifications through Serial Monitor.

> **Note**: Physical hardware was not used; data is simulated, and TensorFlow Lite integration remains as placeholders due to lack of a labeled dataset.

## Future Work
- **Hardware Integration**: Implement with real QMI8658 accelerometer/gyroscope.
- **TensorFlow Lite Model**: Integrate a trained model for activity classification once a labeled dataset is available.

1. **Clone this repository**  
   ```bash
   git clone (https://github.com/Yashomati07/Dog-Activity-Tracke).git
   cd dog-activity-tracker

