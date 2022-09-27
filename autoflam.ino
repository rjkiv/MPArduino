// Listens for drum inputs, and if two cymbals are detected,
// will automatically delay one cymbal to prevent the MPA glitch.
#include <AsyncTimer.h>
#include <MIDI.h>

AsyncTimer t;
unsigned long lastCymbal = millis();
unsigned int flamAmt = 15;
const int cymbal_notes[] = {22, 26, 42, 46, 54, 51, 53, 56, 59, 49, 52, 55, 57, 41, 43};
MIDI_CREATE_DEFAULT_INSTANCE();

// per bookreader's js - CHECK THIS EVERY TIME POLLING THE MIDI INPUT PICKS UP A NOTE:
// if note[2] (or channel) > 0 and note[0] (or pitch) >= 144 and note[0] (or pitch) <= 159):
//    if the length of note[] is 3 (?) and note[1] (or velocity) is found in cymbal_notes:
//        if millis() - lastCymbal < flamAmt:
//              delay sending the note out via setTimeOut
//        else:
//              lastCymbal = millis()
//              send the note out
//    else:
//        send the note out


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
