#include <Servo.h>

// Motor pins for L298N
const int ENA = 3;  // PWM for speed
const int IN1 = 5;  // Direction 1
const int IN2 = 6;  // Direction 2

// Servo control
Servo servo1;
#define SERVOMIN 60
#define SERVOMID 90
#define SERVOMAX 120
#define TurnRight servo1.write(SERVOMIN)
#define TurnMid servo1.write(SERVOMID)
#define TurnLeft servo1.write(SERVOMAX)

// Lights
const int light1 = 12;  // Front light
const int light2 = 13;  // Back light

// Variables
char ch;
int vSpeed = 255;  // Motor speed (0–255)

void setup() {
  Serial.begin(9600);  // RX=0, TX=1 for Bluetooth
  servo1.attach(2);    // Steering servo
  TurnMid;             // Set to center

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(light1, OUTPUT);
  pinMode(light2, OUTPUT);

  stopMotor();  // Ensure stopped at start
  digitalWrite(light1, LOW);
  digitalWrite(light2, LOW);
}

void loop() {
  if (Serial.available()) {
    ch = Serial.read();
    Serial.println(ch);  // Optional: debug via Serial Monitor

    switch (ch) {
      // Movement
      case 'F':
        moveForward();
        break;

      case 'B':
        moveBackward();
        break;

      case 'f':
        stopMotor();
        break;

      case 'b':
        stopMotor();
        break;

      // Steering
      case 'L':
        TurnLeft;
        break;

      case 'l':
        TurnMid;
        break;

      case 'R':
        TurnRight;
        break;

      case 'r':
        TurnMid;
        break;

      // Lights
      case 'U':
        digitalWrite(light1, HIGH);  // Front ON
        break;

      case 'u':
        digitalWrite(light1, LOW);  // Front OFF
        break;

      case 'V':
        digitalWrite(light2, HIGH);  // Back ON
        break;

      case 'v':
        digitalWrite(light2, LOW);  // Back OFF
        break;

      default:
        break;
    }
  }
}

// Move forward
void moveForward() {
  analogWrite(ENA, vSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

// Move backward
void moveBackward() {
  analogWrite(ENA, vSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

// Stop motor
void stopMotor() {
  analogWrite(ENA, 0);     // Cut PWM
  digitalWrite(IN1, LOW);  // Set both inputs LOW
  digitalWrite(IN2, LOW);
}