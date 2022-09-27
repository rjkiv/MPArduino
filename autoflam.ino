// Listens for drum inputs, and if two cymbals are detected,
// will automatically delay one cymbal to prevent the MPA glitch.
#include <AsyncTimer.h>
#include <MIDI.h>

AsyncTimer t;
MIDI_CREATE_DEFAULT_INSTANCE();

void handleNoteOn(byte channel, byte pitch, byte velocity){
//  printNote(int(channel), int(pitch), int(velocity));
  digitalWrite(LED_BUILTIN, HIGH);
  MIDI.sendNoteOn(pitch, velocity, channel);
}

void handleNoteOff(byte channel, byte pitch, byte velocity){
  digitalWrite(LED_BUILTIN, LOW);
  MIDI.sendNoteOff(pitch, velocity, channel);
}

// setup code, runs once
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
//  t.setInterval([]() { digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); }, 1000);
}

// main code, runs repeatedly
void loop() {
//  t.handle();
  MIDI.read();
}
