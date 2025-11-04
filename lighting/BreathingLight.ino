/*
  BreathingLight.ino
  Creates a soft pulsing glow (ideal for magic orb, moonlight, etc.)
*/

#define LED_PIN 9
int fadeAmount = 5;
int brightness = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, brightness);
  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // Reverse at extremes
  }

  delay(30); // Adjust for speed of "breathing"
}
