/*
  MotionTrigger.ino
  Turns light on when motion is detected, off after timeout.
*/

#define LED_PIN 9
#define MOTION_PIN 2
#define TIMEOUT 10000  // Time light stays on after motion (ms)

unsigned long lastMotion = 0;
bool lightOn = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTION_PIN, INPUT);
}

void loop() {
  if (digitalRead(MOTION_PIN) == HIGH) {
    analogWrite(LED_PIN, 255);
    lightOn = true;
    lastMotion = millis();
  }

  if (lightOn && millis() - lastMotion > TIMEOUT) {
    analogWrite(LED_PIN, 0);
    lightOn = false;
  }

  delay(100);
}
