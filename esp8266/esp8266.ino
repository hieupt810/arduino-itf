#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#include <Servo.h>

// WiFi
const char* ssid = "JPhone";
const char* password = "giongpassnhami";

ESP8266WebServer server(80);

int LED = 5;

// DHT11
#define DHT_PIN 2
#define DHT_TYPE DHT11

DHT dht(DHT_PIN, DHT_TYPE);

// Servo
#define SERVO_PIN 4

Servo servo;

void handle_led_on() {
  Serial.println("LED on");

  digitalWrite(LED, HIGH);
  server.send(200, "text/plain", "Đèn đã được bật");
}

void handle_led_off() {
  Serial.println("LED off");

  digitalWrite(LED, LOW);
  server.send(200, "text/plain", "Đèn đã được tắt");
}

void handle_temperature() {
  float temperature = dht.readTemperature();
  Serial.println(temperature);
  if (isnan(temperature)) {
    server.send(500, "text/plain")
  }
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("Connected");

  server.on("/led=on", handle_led_on);
  server.on("/led=off", handle_led_off);

  server.enableCORS(true);
  server.begin();

  Serial.println("Server started");
  Serial.print("IP Address of network: http://");
  Serial.println(WiFi.localIP());

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop() {
  server.handleClient();
}
