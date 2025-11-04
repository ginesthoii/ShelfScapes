/*
  CandleFlicker.ino
  Simulates warm, random candlelight flicker using PWM.
*/

#define LED_PIN 9

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int flicker = random(120, 255); // Random brightness range
  analogWrite(LED_PIN, flicker);
  delay(random(30, 150));         // Random speed variation
}
