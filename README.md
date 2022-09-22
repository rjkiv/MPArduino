# MPArduino
Aims to mitigate RB3's notorious MPA double-cymbal glitch via an autoflam script running on an Arduino.

# Problem Statement
Rock Band 3 (RB3) is a fantastic rhythm game, with one of its killer features being the ability to plug in MIDI drums, guitars, or keyboards into the Madcatz Midi Pro Adapter (MPA). 
However, when playing the Pro Drums mode with an electronic drum kit connected to the MPA, there is a notorious bug where if you play two cymbals simultaneously alongside a kick, the game will incorrectly read one of the cymbals as a tom, and break your current note combo.

Currently, [there exists a webpage by bookreader52](https://bookreader52.bitbucket.io/) that gets around this by delaying one of the cymbal inputs; however, it requires a desktop, laptop, or any device that can read MIDI and HTML, which can make for a cumbersome setup. 
I wanted a fix for this glitch without having to power on and lug a computer to my e-kit everytime I wanted to play the pro drums, so I decided to port bookreader's scripts to an Arduino.
An Arduino microcontroller not only consumes much less power than a traditional computer, but it also makes for a much lighter and more durable device - so much so that you could even mount it to your e-kit with the right 3D printed enclosure.

# Hardware Setup
I/O: USB-B from the e-kit goes into the Arduino via USB-A. USB-A from the MPA goes into the Xbox as normal, but the MIDI goes into the Arduino either via a MIDI to USB-A adapter, or a MIDI cable directly.

The USB-B port outputs the MIDI to the Arduino, where the script will adjust the cymbal output times, then send the cymbal signals back to the MPA directly. The MPA then sends said signals to the Xbox.
