#define trigPin 4
#define echoPin 18
#define closeLedPin 22
#define farLedPin 23
#define buzzerPin 24 // Define the pin for the buzzer

const int distanceThreshold = 20; // Distance threshold in cm

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(closeLedPin, OUTPUT);
  pinMode(farLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as output
}

void loop() {
  long duration, distance;

  // Clear the TRIG_PIN
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the TRIG_PIN on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the ECHO_PIN, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the LEDs and buzzer based on the distance
  if (distance <= distanceThreshold) {
    digitalWrite(closeLedPin, HIGH);
    digitalWrite(farLedPin, LOW);
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
  } else {
    digitalWrite(closeLedPin, LOW);
    digitalWrite(farLedPin, HIGH);
    digitalWrite(buzzerPin, LOW); // Turn off the buzzer
  }

  delay(500); // Wait for 500ms before the next measurement
}
