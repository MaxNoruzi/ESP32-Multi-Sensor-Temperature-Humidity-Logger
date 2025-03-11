#include "DHT.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <ESP_Google_Sheet_Client.h>

#define DHTPIN 14
#define DHTTYPE DHT11

const int oneWireBus = 12;
int analog_temp_pin = 2;
int dTemp_analog_temp_pin = 4;

DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire(oneWireBus);

DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(analog_temp_pin, INPUT);
  pinMode(dTemp_analog_temp_pin, INPUT);
}

void loop() {
  delay(1000);
  
  float dht_humidity = dht.readHumidity();
  float dht_temp_cel = dht.readTemperature();

  if (isnan(dht_humidity) || isnan(dht_temp_cel)) {
    Serial.println("Echec reception");
    return;
  }

  
  // Serial.print("dht_humidity: ");
  // Serial.print(dht_humidity);
  // Serial.print("%  dht_temp_cel: ");
  // Serial.print(dht_temp_cel);
  // Serial.println("°C");

  sensors.begin();
  sensors.requestTemperatures(); 
  float dallas_temperatureC = sensors.getTempCByIndex(0);
  // Serial.print(dallas_temperatureC);
  // Serial.println("ºC");




  int readVal = analogRead(analog_temp_pin);
  double temp =  Thermistor(readVal);
  // Serial.print("analog temprature: ");
  // Serial.print(temp);
  // Serial.println("ºC");

  int valFromDigitalTemp = analogRead(dTemp_analog_temp_pin);
  // Serial.println(valFromDigitalTemp);


  Serial.print(dht_humidity);
  Serial.print(",");
  Serial.print(dht_temp_cel);
  Serial.print(",");
  Serial.print(dallas_temperatureC);
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(valFromDigitalTemp);
  Serial.println();
}

double Thermistor(int RawADC) {
  float R_ohms = 10000 * (1023.0 / (float)RawADC - 1.0);
  float temp_C = (1.0 / (0.001129148 + (0.000234125*log(R_ohms)) + 0.0000000876741*log(R_ohms)*log(R_ohms)*log(R_ohms)))-273.15;
  return temp_C;
}