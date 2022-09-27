// Listens for drum inputs, and if two cymbals are detected,
// will automatically delay one cymbal to prevent the MPA glitch.
#include <AsyncTimer.h>
#include <MIDI.h>

AsyncTimer t;
unsigned long lastCymbal = 0;
unsigned long flamAmt = 15;
const int cymbal_notes[] = {22, 26, 42, 46, 54, 51, 53, 56, 59, 49, 52, 55, 57, 41, 43};
MIDI_CREATE_DEFAULT_INSTANCE();

bool note_in_cymbal_notes(int note){
  for(int i = 0; i < 15; i++){
    if(note == cymbal_notes[i]) return true;
  }
  return false;
}

void sendNote(byte channel, byte pitch, byte velocity, bool on){
  if(on) MIDI.sendNoteOn(pitch, velocity, channel);
  else MIDI.sendNoteOff(pitch, velocity, channel);
}

void handleDrumNote(byte channel, byte pitch, byte velocity, bool on){
  digitalWrite(LED_BUILTIN, on);
  if(int(channel) > 0 && int(pitch) >= 144 && int(pitch) <= 159){
    if(note_in_cymbal_notes(int(velocity))){
      if(millis() - lastCymbal < flamAmt){
         //send the note out delayed
         t.setTimeout([=]() { sendNote(channel, pitch, velocity, on); }, flamAmt);
      }
      else{
        lastCymbal = millis();
        sendNote(channel, pitch, velocity, on);
      }
    }
    else sendNote(channel, pitch, velocity, on);
  }
  
}


void handleNoteOn(byte channel, byte pitch, byte velocity){
  handleDrumNote(channel, pitch, velocity, true);
}

void handleNoteOff(byte channel, byte pitch, byte velocity){
  handleDrumNote(channel, pitch, velocity, false);
}

// setup code, runs once
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
}

// main code, runs repeatedly
void loop() {
  t.handle();
  MIDI.read();
}
