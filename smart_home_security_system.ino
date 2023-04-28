// PIR sensor pin
int pirPin = 2;

// Light sensor pin
int lightPin = A0;

// LED pin
int ledPin = 3;

// Buzzer pin
int buzzerPin = 4;

// Variables to store sensor readings
int pirState = LOW;
int lightValue = 0;

void setup() {
  // Set up the pins
  pinMode(pirPin, INPUT);
  pinMode(lightPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the PIR sensor
  pirState = digitalRead(pirPin);
  
  // Read the light sensor
  lightValue = analogRead(lightPin);
  
  // Print the sensor readings
  Serial.print("PIR sensor: ");
  Serial.print(pirState);
  Serial.print(", Light sensor: ");
  Serial.print(lightValue);
  Serial.println();
  
  // Check if motion is detected by the PIR sensor
  if (pirState == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    digitalWrite(buzzerPin, HIGH); // Sound the buzzer
    Serial.println("Motion detected!");
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    digitalWrite(buzzerPin, LOW); // Stop the buzzer
  }
  
  // Check the light level
  if (lightValue < 500) { // If light level is below 500
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Door unlocked!");
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.println("Door locked!");
  }
  
  delay(500);
}
