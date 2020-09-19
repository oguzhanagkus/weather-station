#include <SoftwareSerial.h>
#include "DHT.h"

#define RX_PIN 2
#define TX_PIN 3
#define DHTPIN 4
#define DHTTYPE DHT22

SoftwareSerial Bluetooth(RX_PIN, TX_PIN);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Bluetooth.begin(9600);
  Bluetooth.println("Welcome!!");

  dht.begin();
}

void loop() {
  delay(10000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);

  Bluetooth.print("Humidity: ");
  Bluetooth.print(h);
  Bluetooth.println("%");
  Bluetooth.print("Temperature: ");
  Bluetooth.print(t);
  Bluetooth.println("C");
  Bluetooth.print("Heat index: ");
  Bluetooth.print(hic);
  Bluetooth.println("C");
  Bluetooth
  .println("----------");
}
