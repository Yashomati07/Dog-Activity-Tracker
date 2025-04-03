# Dog-Activity-Tracker
The Dog Activity Tracker is a motion-based tracking system built on the ESP32-S3 to monitor and classify a dog's activities in real-time. It uses an accelerometer + gyroscope (QMI8658) to detect movement and categorize activities into Resting, Walking, Running, and Playing.
# 🐶 Dog Activity Tracker  

A motion-based tracking system using **ESP32-S3** to monitor and classify a dog's activities in real-time. This project detects movement using an **accelerometer + gyroscope (QMI8658)** and categorizes activities into **Resting, Walking, Running, and Playing**.  

## 📌 Features  

✅ **Activity Classification** – Detects and categorizes movements  
✅ **Wake-on-Motion** – Saves power by entering deep sleep mode when inactive  
✅ **Data Storage with LittleFS** – Logs activity data in 10-minute intervals  
✅ **Time Synchronization** – Uses **NTP** for accurate timekeeping  
✅ **BLE Connectivity** – Syncs data with a mobile app (planned feature)  
✅ **TensorFlow Lite Integration** – Future support for ML-based activity classification  

## 🛠 Tech Stack & Dependencies  

- **ESP32-S3** microcontroller  
- **QMI8658** Accelerometer + Gyroscope  
- **ESP32 Arduino Core (v2.0.14)**  
- **LittleFS** (File storage)  
- **TensorFlow Lite for ESP32** (Version TBD)  
- **BLE & ArduinoOTA Libraries**  

## 🚀 Getting Started  

### 📥 Prerequisites  

Ensure you have the following installed:  

- **Arduino IDE** (latest version)  
- **ESP32 Board Package** (v2.0.14)  
- **Required Libraries:**  
  - `ESP32 Arduino Core`  
  - `LittleFS`  
  - `TensorFlow Lite for ESP32`  
  - `BLE`  
  - `ArduinoOTA`  

### 📌 Installation Steps  

1. **Clone this repository**  
   ```bash
   git clone https://github.com/your-username/dog-activity-tracker.git
   cd dog-activity-tracker

