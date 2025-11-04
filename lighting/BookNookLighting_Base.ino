/*
  BookNookLighting_Base.ino
  Universal controller for small LED lighting projects.
  Supports: brightness, ambient light (LDR), and motion sensors.
*/

#define LED_PIN 9           // PWM pin for LED or LED strip
#define LDR_PIN A0          // Optional light sensor
#define MOTION_PIN 2        // Optional PIR motion sensor
#define BASE_BRIGHTNESS 180 // 0–255 brightness
#define DELAY_TIME 100      // ms between sensor checks

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTION_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int ambient = analogRead(LDR_PIN);      // Read light level (0–1023)
  bool motion = digitalRead(MOTION_PIN);  // Read motion (HIGH/LOW)

  // Turn on lights if it's dark or motion detected
  if (ambient < 400 || motion) {
    analogWrite(LED_PIN, BASE_BRIGHTNESS);
  } else {
    analogWrite(LED_PIN, 0);
  }

  delay(DELAY_TIME);
}
