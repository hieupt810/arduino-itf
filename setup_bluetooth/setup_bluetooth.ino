#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);
}

void loop() {
  if (BTSerial.available()) {
    Serial.write(BTSerial.read());
  }

  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
