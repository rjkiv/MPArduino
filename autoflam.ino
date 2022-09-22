// Listens for drum inputs, and if two cymbals are detected,
// will automatically delay one cymbal to prevent the MPA glitch.
#include <AsyncTimer.h>

AsyncTimer t;

// setup code, runs once
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  t.setInterval([]() { digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); }, 1000);
}

// main code, runs repeatedly
void loop() {
  t.handle();
}
