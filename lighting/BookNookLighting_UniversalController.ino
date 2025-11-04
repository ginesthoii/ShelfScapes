/*
  BookNookLighting_UniversalController.ino
  ----------------------------------------------------
  Universal, multi-mode lighting controller for book nooks.
  Supports:
   - Candle flicker
   - Breathing light
   - Motion trigger
   - Day/Night fade
  ----------------------------------------------------
  Select mode with:
   • MODE_PIN: DIP switch or jumper (binary read)
   • Or set mode manually below
  ----------------------------------------------------
  Compatible with Arduino Nano, Uno, or ESP32 (5V logic)
*/

#define LED_PIN 9
#define MOTION_PIN 2
#define LDR_PIN A0
#define MODE_PIN A1 // optional selector switch

// Uncomment to lock a mode manually
//#define FIXED_MODE 1   // 1=Candle, 2=Breathing, 3=Motion, 4=DayNight

// --- Settings ---
int brightness = 180;
const unsigned long TIMEOUT = 10000; // motion timeout (ms)

// --- Variables ---
int mode = 1;
unsigned long lastMotion = 0;
bool lightOn = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTION_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(MODE_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
#ifdef FIXED_MODE
  mode = FIXED_MODE;
#else
  mode = map(analogRead(MODE_PIN), 0, 1023, 1, 4); // read switch or pot
#endif

  switch (mode) {
    case 1: candleFlicker(); break;
    case 2: breathingLight(); break;
    case 3: motionTrigger(); break;
    case 4: dayNightCycle(); break;
    default: analogWrite(LED_PIN, 0); break;
  }
}

// ------------------------------------------------------------
// Mode 1: Candle Flicker
// ------------------------------------------------------------
void candleFlicker() {
  int flicker = random(120, 255);
  analogWrite(LED_PIN, flicker);
  delay(random(30, 150));
}

// ------------------------------------------------------------
// Mode 2: Breathing Light
// ------------------------------------------------------------
void breathingLight() {
  static int brightness = 0;
  static int fadeAmount = 5;

  analogWrite(LED_PIN, brightness);
  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 255) fadeAmount = -fadeAmount;
  delay(30);
}

// ------------------------------------------------------------
// Mode 3: Motion Triggered Light
// ------------------------------------------------------------
void motionTrigger() {
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

// ------------------------------------------------------------
// Mode 4: Day/Night Fade Cycle
// ------------------------------------------------------------
void dayNightCycle() {
  const int STEP_DELAY = 50;
  const int CYCLE_TIME = 60000;

  for (int b = 0; b <= 255; b++) {
    analogWrite(LED_PIN, b);
    delay(STEP_DELAY);
  }
  delay(CYCLE_TIME / 4);

  for (int b = 255; b >= 0; b--) {
    analogWrite(LED_PIN, b);
    delay(STEP_DELAY);
  }
  delay(CYCLE_TIME / 2);
}
