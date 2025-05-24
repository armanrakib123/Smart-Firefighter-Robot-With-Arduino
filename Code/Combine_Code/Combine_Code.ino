#include <Servo.h>

const int flameSensorPin = 10;
const int relayPin = 11;

const int ENA = 3;
const int IN1 = 5;
const int IN2 = 6;

Servo servo1;
#define SERVOMIN 60
#define SERVOMID 90
#define SERVOMAX 120
#define TurnRight servo1.write(SERVOMIN)
#define TurnMid servo1.write(SERVOMID)
#define TurnLeft servo1.write(SERVOMAX)

const int light1 = 12;
const int light2 = 13;

char ch;
int vSpeed = 255;

unsigned long lastFlameCheck = 0;
const unsigned long flameInterval = 500;

unsigned long lastBTCheck = 0;
const unsigned long btInterval = 50;

void setup() {
  Serial.begin(9600);
  pinMode(flameSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  servo1.attach(2);
  TurnMid;

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  stopMotor();

  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
}

void loop() {
  unsigned long currentMillis = millis();

  // Flame sensor logic every 500 ms
  if (currentMillis - lastFlameCheck >= flameInterval) {
    lastFlameCheck = currentMillis;
    int flameDetected = digitalRead(flameSensorPin);
    digitalWrite(relayPin, flameDetected == LOW ? LOW : HIGH);
  }

  // Bluetooth command handling every 50 ms
  if (currentMillis - lastBTCheck >= btInterval) {
    lastBTCheck = currentMillis;
    if (Serial.available()) {
      ch = Serial.read();
      processCommand(ch);
    }
  }
}

void processCommand(char ch) {
  switch (ch) {
    case 'F': moveForward(); break;
    case 'B': moveBackward(); break;
    case 'f': stopMotor(); break;
    case 'b': stopMotor(); break;
    case 'L': TurnLeft; break;
    case 'l': TurnMid; break;
    case 'R': TurnRight; break;
    case 'r': TurnMid; break;
    case 'U': digitalWrite(light1, HIGH); break;
    case 'u': digitalWrite(light1, LOW); break;
    case 'V': digitalWrite(light2, HIGH); break;
    case 'v': digitalWrite(light2, LOW); break;
    default: break;
  }
}

void moveForward() {
  analogWrite(ENA, vSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void moveBackward() {
  analogWrite(ENA, vSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void stopMotor() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
