#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Servo
Servo gateServo;

// Pins
#define TRIG 5
#define ECHO 19
#define BUZZER 23
#define LED 2
#define SERVO_PIN 18

long duration;
int distance;

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  gateServo.attach(SERVO_PIN);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
    while (1);
  }

  display.setTextColor(WHITE); // IMPORTANT

  openGate();
}

// ---------------- LOOP ----------------
void loop() {
  distance = getDistance();
  Serial.println(distance);

  if (distance < 20) {
    closeGate();
  } else {
    openGate();
  }

  delay(500);
}

// ---------------- DISTANCE ----------------
int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  int dist = duration * 0.034 / 2;

  return dist;
}

// ---------------- CLOSE GATE ----------------
void closeGate() {
  gateServo.write(90);

  digitalWrite(LED, HIGH);
  digitalWrite(BUZZER, HIGH);

  display
