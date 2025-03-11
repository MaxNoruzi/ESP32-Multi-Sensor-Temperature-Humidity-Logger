Project Overview

This project is an ESP32-based multi-sensor monitoring system that collects temperature and humidity data from multiple sensors. The data is printed in CSV format for logging and can be integrated with Google Sheets for cloud storage.

Features

✅ Multi-Sensor Data Collection

DHT11 for Temperature & Humidity

DS18B20 Digital Temperature Sensor

Analog Thermistor for Temperature Measurement

Additional Digital Temperature Sensor (Analog Output)

✅ CSV Data Output for easy logging

✅ Expandable for IoT Applications

✅ Potential Google Sheets Integration (via ESP_Google_Sheet_Client)
![image](https://github.com/user-attachments/assets/d77108f6-a0c9-4264-aede-840ac4ac1720)
How It Works

1️⃣ Setup Phase

Initializes DHT11, DS18B20, and Thermistor.

Sets input pins for analog and digital sensors.

2️⃣ Data Collection Loop

Reads temperature & humidity from DHT11.

Reads temperature from DS18B20.

Reads raw analog value from the thermistor and converts it to Celsius using the Steinhart-Hart equation.

Reads raw analog value from another digital temperature sensor.

Prints all data in CSV format:
