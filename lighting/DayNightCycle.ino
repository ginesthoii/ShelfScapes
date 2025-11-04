/*
  DayNightCycle.ino
  Gradually fades light in/out to mimic sunrise/sunset or a 24-hour rhythm.
*/

#define LED_PIN 9
#define CYCLE_TIME 60000 // Full fade cycle time (ms)
#define STEP_DELAY 50

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Fade up (sunrise)
  for (int b = 0; b <= 255; b++) {
    analogWrite(LED_PIN, b);
    delay(STEP_DELAY);
  }

  // Midday pause
  delay(CYCLE_TIME / 4);

  // Fade down (sunset)
  for (int b = 255; b >= 0; b--) {
    analogWrite(LED_PIN, b);
    delay(STEP_DELAY);
  }

  // Night pause
  delay(CYCLE_TIME / 2);
}
