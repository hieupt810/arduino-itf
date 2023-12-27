#include <IRremote.hpp>
#include <DHT.h>

#define DHTPin 4
#define DHTType DHT11

DHT HT(DHTPin, DHTType);

const int IR_SEND_PIN = 3;
const int SENSOR_PIN = 0;

void setup() {
  Serial.begin(9600);
  IrSender.begin(IR_SEND_PIN);
  HT.begin();
  delay(100);
}

void loop() {
  float humi = HT.readHumidity();
  float tempC = HT.readTemperature();

  Serial.print("Humidity: ");
  Serial.println(humi);

  Serial.print("Temperature C: ");
  Serial.println(tempC);

  // if (sensor <= 450) {
  //   IrSender.sendNECRaw(1);
  //   delay(500);
  // } else {
  //   IrSender.sendNECRaw(50);
  //   delay(500);
  // }

  Serial.println("------------------");
  delay(100);
}