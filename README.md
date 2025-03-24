# 🌡️ Arduino Temperature Monitoring System

This simple Arduino project reads ambient temperature using a digital sensor and displays or logs the data. Ideal for learning sensor integration, serial communication, or for building the foundation of an IoT system.

---

## 🔧 Features

- 🌡️ Real-time temperature reading
- 📟 Serial output to monitor temperature changes
- 🧪 Support for sensors like **DHT11**, **DHT22**, or **LM35**
- ⏱️ Adjustable delay interval for periodic monitoring

---

## 🧰 Hardware Used

- Arduino UNO / Nano / ESP32  
- Temperature Sensor (e.g., DHT11 / DHT22 / LM35)  
- 10K Resistor (for DHT sensors)  
- Breadboard and Jumper Wires  
- USB Cable for Serial Monitor

---

## 📌 Wiring Guide (for DHT11)

| Component | Arduino Pin |
|----------|--------------|
| VCC      | 5V or 3.3V    |
| GND      | GND          |
| DATA     | D2 (example)  |

> 🛠 If you're using LM35, connect the analog output to A0 instead.

---

## 🛠 Setup & Run

1. Install the required sensor library (e.g., `DHT` library by Adafruit if using DHT11/DHT22)
2. Connect your sensor using the wiring table above
3. Upload `temp (1).ino` to your board
4. Open **Serial Monitor** (9600 baud) to view live temperature readings

---

## 🧠 Possible Extensions

- 🌐 Add Wi-Fi (ESP32) to log data to cloud or Thingspeak
- 📈 Display temperature on OLED/LCD screen
- 🔔 Trigger buzzer/LED if temperature exceeds threshold
- 🗂️ Store data to SD card or EEPROM

---

## 📬 Contact

Open a pull request or an issue if you'd like to contribute, improve, or request help with extensions.

