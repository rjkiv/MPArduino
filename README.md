# MPArduino
Aims to mitigate RB3's notorious MPA double-cymbal glitch via an autoflam script running on an Arduino.

# Problem Statement
Rock Band 3 (RB3) is a fantastic rhythm game, with one of its killer features being the ability to plug in MIDI drums, guitars, or keyboards into the Madcatz Midi Pro Adapter (MPA). 
However, when playing the Pro Drums mode with an electronic drum kit connected to the MPA, there is a notorious bug where if you play two cymbals simultaneously alongside a kick, the game will incorrectly read one of the cymbals as a tom, and break your current note combo.

Currently, [there exists a webpage by bookreader52](https://bookreader52.bitbucket.io/) that gets around this by delaying one of the cymbal inputs; however, it requires a desktop, laptop, or any device that can read MIDI and HTML, which can make for a cumbersome setup. 
I wanted a fix for this glitch without having to power on and lug a computer to my e-kit everytime I wanted to play the pro drums, so I decided to port bookreader's scripts to an Arduino.
An Arduino microcontroller not only consumes much less power than a traditional computer, but it also makes for a much lighter and more durable device - so much so that you could even mount it to your e-kit with the right 3D printed enclosure.

# Hardware Setup

Other slightly different setups *may* work with this Arduino code; however, below is the setup I tested in order to make this work.

Arduino: An Uno with a MIDI shield attached. I used the MIDI shield's MIDI IN and OUT ports.

I/O: 
 - USB from the e-kit goes into the Arduino USB in order to supply power. You could use an external battery if you wanted to; however, I felt that using the e-kit's USB port was more seamless.
 - MIDI cable from the e-kit into the MIDI-IN port of the Arduino. I *think* you could use a USB to MIDI converter cable if your e-kit does not have a MIDI port, but I haven't tested this for myself.
 - A second MIDI cable going from the MIDI-OUT port of the Arduino into the MIDI port of the MPA.
 - MPA USB goes into the console as normal.

The script within the Arduino will adjust the cymbal output times, then send the cymbal signals back to the MPA directly. The MPA then sends said signals to the Xbox as normal.

# Arduino Script

To upload the included script successfully onto an Uno (or whatever board you intend to use), you will need the AsyncTimer and MIDI library. You can find both in the library search window (via Sketch -> Include Library -> Manage Libraries), or you can visit their repos [here](https://github.com/Aasim-A/AsyncTimer) and [here](https://github.com/FortySevenEffects/arduino_midi_library), respectively.

# Acknowledgements

I would like to recognize the following people for their help in making this project possible:
 - [Aasim-A](https://github.com/Aasim-A), for creating the Arduino AsyncTimer library.
 - [FortySevenEffects](https://github.com/FortySevenEffects), for creating the Arduino MIDI library.
 - [bookreader52](https://www.youtube.com/channel/UC1EuxOVixdHZ0ENcvJJ3n1g/), for providing the JS code for his web autoflam script, as well as walking me through (and providing) the ideal hardware setup for this project.
