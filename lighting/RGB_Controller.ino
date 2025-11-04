/*
  RGB_Controller.ino
  Example for individually addressable LEDs (Neopixels).
  Use Adafruit_NeoPixel library.
*/

#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUMPIXELS 8

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  // Cycle colors
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(255, 80, 0)); // Warm orange
  }
  strip.show();
  delay(1000);

  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255)); // Cool blue
  }
  strip.show();
  delay(1000);
}
