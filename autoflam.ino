// Listens for drum inputs, and if two cymbals are detected,
// will automatically delay one cymbal to prevent the MPA glitch.
#include <AsyncTimer.h>
#include <MIDI.h>

AsyncTimer t;
MIDI_CREATE_DEFAULT_INSTANCE();

void printNote(byte channel, byte pitch, byte velocity){
  Serial.print("[");
  Serial.print(channel);
  Serial.print(", ");
  Serial.print(pitch);
  Serial.print(", ");
  Serial.print(velocity);
  Serial.print("]\n");
}

void handleNoteOn(byte channel, byte pitch, byte velocity){
//  printNote(int(channel), int(pitch), int(velocity));
  digitalWrite(LED_BUILTIN, HIGH);
}

void handleNoteOff(byte channel, byte pitch, byte velocity){
  digitalWrite(LED_BUILTIN, LOW);
}

// setup code, runs once
void setup() {
//  Serial.begin(115200);
//  while(!Serial);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
//  Serial.println("Ready to play.");
//  t.setInterval([]() { digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); }, 1000);
}

// main code, runs repeatedly
void loop() {
//  t.handle();
  MIDI.read();
}
