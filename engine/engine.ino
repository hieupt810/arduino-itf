#include <SoftwareSerial.h>
#include <Stepper.h>
#include <Servo.h>

void use_stepper(int degree, long speed = 14, int steps = 2048, int in1 = 3, int in2 = 5, int in3 = 4, int in4 = 6) {
  Stepper myStepper = Stepper(steps, in1, in2, in3, in4);
  myStepper.setSpeed(14);

  if (degree == 0) {
    myStepper.step(0);
  } else {
    int value = steps / (360 / degree);
    myStepper.step(value);
  }
}

void use_dc(int speed = 150, bool clockWise = true, int in1Pin = 12, int in2Pin = 13) {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  if (clockWise) {
    analogWrite(in1Pin, speed);
    analogWrite(in2Pin, 0);
  } else {
    analogWrite(in1Pin, 0);
    analogWrite(in2Pin, speed);
  }
}

void use_servo(int degree, int servoPin = 2) {
  Servo servo;
  servo.attach(servoPin);

  servo.write(degree);
  delay(500);
  servo.write(0);
  delay(500);
}

SoftwareSerial BTSerial(10, 11);

void setup() {
  BTSerial.begin(9600);
}

void loop() {
  while (BTSerial.available()) {
    String c = BTSerial.readString();
  }
  delay(5);
}
