#include <DHT.h>

int get_light_value(int limit, int sensorPin = 0) {
  // Light Sensor
  pinMode(sensorPin, OUTPUT);

  return analogRead(sensorPin);
}

int get_temperature(int sensorPin = 4, bool fahrenheit = false) {
  // DHT11 Sensor
  DHT sensor(sensorPin, "DHT11");
  sensor.begin();
  delay(10);

  return sensor.readTemperature(fahrenheit);
}

int getHumidity(int sensorPin = 4) {
  // DHT11 Sensor
  DHT sensor(sensorPin, "DHT11");
  sensor.begin();
  delay(50);

  return sensor.readHumidity();
}

bool get_line(int sensorPin) {
  // Line Sensor
  // Value 0 - White line - Has a reflective surface
  // Value 1 - Black line
  return digitalRead(sensorPin);
}

int get_distance(int triggerPin = 5, int echoPin = 3) {
  // Ultrasonic Sensor
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(triggerPin, LOW);
  delay(2);
  digitalWrite(triggerPin, HIGH);
  delay(10);
  digitalWrite(triggerPin, LOW);
  int duration = pulseIn(echoPin, HIGH);

  // Measure: centimeter
  return duration * 0.034 / 2;
}

bool get_motion(int sensorPin = 2) {
  // Digital Infrared Motion Sensor
  pinMode(sensorPin, INPUT);

  // Value 1 - Something moves
  // Value 0 - Nothing moves
  return digitalRead(sensorPin);
}

int get_gas_value(int sensorPin = 0) {
  return analogRead(sensorPin);
}

int get_joystick_value(int directionPin) {
  return analogRead(directionPin);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
}
