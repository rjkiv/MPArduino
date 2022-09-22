# MPArduino
Aims to mitigate RB3's notorious MPA double-cymbal glitch via an autoflam script.

# Hardware Setup
I/O: USB-B from the e-kit goes into the Arduino via USB-A. USB-A from the MPA goes into the Xbox as normal, but the MIDI goes into the Arduino either via a MIDI to USB-A adapter, or a MIDI cable directly.

The USB-B port outputs the MIDI to the Arduino, where the script will adjust the cymbal output times, then send the cymbal signals back to the MPA directly. The MPA then sends said signals to the Xbox.
