# 🚆 Automated Railway Gate System using ESP32

## 📌 Overview
This project is an automated railway gate system designed to improve safety at railway crossings using ESP32.

It detects an approaching train and automatically closes the gate while providing visual and audio alerts.

---

## ⚙️ Features
- Automatic gate control using servo motor
- Ultrasonic-based train detection
- OLED display for live status
- LED and buzzer alerts
- Low-cost and scalable design

---

## 🔧 Components Used
- ESP32
- Ultrasonic Sensor (HC-SR04)
- Servo Motor (SG90)
- OLED Display (SSD1306)
- Buzzer
- LED + Resistor

---

## 🔌 Pin Configuration

| Component | ESP32 Pin |
|----------|----------|
| TRIG     | GPIO 5   |
| ECHO     | GPIO 19  |
| Servo    | GPIO 18  |
| OLED SDA | GPIO 21  |
| OLED SCL | GPIO 22  |
| Buzzer   | GPIO 23  |
| LED      | GPIO 2   |

---

## ⚠️ Important Notes
- Use a voltage divider for ECHO pin (5V → 3.3V)
- Ensure common ground
- Servo requires 5V power supply

---

## 🚀 Working
1. Ultrasonic sensor detects approaching train  
2. Gate closes automatically  
3. Alerts are activated  
4. Gate opens after train passes  

---


## 🔮 Future Improvements
- GSM alert system
- Dual sensor implementation
- Camera monitoring system

---

## 👨‍💻 Author
Sairam
