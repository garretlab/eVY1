#include "Arduino.h"
#include "eVY1.h"

/*
 * Constructor
 */
eVY1::eVY1(Stream *port) : midiClass(port){
}

void eVY1::eVocaloid(uint8_t mode, char *lyrics) {
  int lyricsLen = strlen(lyrics);
  midiClass::serialPort->write(0xf0);
  midiClass::serialPort->write(0x43);
  midiClass::serialPort->write(0x79);
  midiClass::serialPort->write(0x09);
  midiClass::serialPort->write((uint8_t)0x00);
  midiClass::serialPort->write(0x50);
  midiClass::serialPort->write(0x10 | mode);
  midiClass::serialPort->write(lyrics);
  midiClass::serialPort->write((uint8_t)0x00);
  midiClass::serialPort->write(0xf7);
}
    

