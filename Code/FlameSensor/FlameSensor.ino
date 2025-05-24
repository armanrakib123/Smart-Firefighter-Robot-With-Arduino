const int flameSensorPin = 10;   // Digital input from flame sensor
const int relayPin = 11;         // Relay control pin

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Turn relay off initially (depends on relay type)
  Serial.begin(9600);
}

void loop() {
  int flameDetected = digitalRead(flameSensorPin); // LOW when flame is detected for most sensors

  if (flameDetected == LOW) {
    Serial.println("Flame detected! Turning on pump.");
    digitalWrite(relayPin, LOW); // Turn ON pump (relay active LOW)
  } else {
    Serial.println("No flame detected.");
    digitalWrite(relayPin, HIGH); // Turn OFF pump
  }
  
  delay(500);
}
