#include "Arduino.h"
#include "midiClass.h"

/*
 * Constructor
 */
midiClass::midiClass(Stream *port) {
  serialPort = port;
}

/*
 * Public methods
 */
void midiClass::keyOff(uint8_t channelNo, uint8_t keyNo, uint8_t velocity) {
  serialPort->write(0x80 | channelNo);
  serialPort->write(keyNo);
  serialPort->write(velocity);
}

void midiClass::keyOn(uint8_t channelNo, uint8_t keyNo, uint8_t velocity) {
  serialPort->write(0x90 | channelNo);
  serialPort->write(keyNo);
  serialPort->write(velocity);
}

void midiClass::controlChange(uint8_t channelNo, uint8_t data1, uint8_t data2) {
  serialPort->write(0xb0 | channelNo);
  serialPort->write(data1);
  serialPort->write(data2);
}

void midiClass::modeMessage(uint8_t channelNo, uint8_t data) {
  serialPort->write(0xb0 | channelNo);
  serialPort->write(data);
}

void midiClass::programChange(uint8_t channelNo, uint8_t voiceNo) {
  serialPort->write(0xc0 | channelNo);
  serialPort->write(voiceNo);
}

void midiClass::channelAfterTouch(uint8_t channelNo, uint8_t data) {
  serialPort->write(0xd0 | channelNo);
  serialPort->write(data);
}

void midiClass::polyphonicAfterTouch(uint8_t channelNo, uint8_t keyNo, uint8_t data) {
  serialPort->write(0xa0 | channelNo);
  serialPort->write(keyNo);
  serialPort->write(data);
}

void midiClass::pitchBandChange(uint8_t channelNo, uint8_t msb, uint8_t lsb) {
  serialPort->write(0xe0 | channelNo);
  serialPort->write(lsb);
  serialPort->write(msb);
}

#ifdef MIDI_COMPILE_SUBCOMMANDS
/* Control Change */
void midiClass::bankSelect(uint8_t channelNo, uint8_t msb, uint8_t lsb) {
  controlChange(channelNo, 0x00, msb);
  controlChange(channelNo, 0x20, lsb);
}

void midiClass::modulataion(uint8_t channelNo, uint8_t data) {
  controlChange(channelNo, 0x01, data);
}

void midiClass::mainVolume(uint8_t channelNo, uint8_t volume) {
  controlChange(channelNo, 0x07, volume);
}

/* Mode Message */
void midiClass::allSoundOff(uint8_t channelNo) {
  modeMessage(channelNo, 0x78);
}

void midiClass::allNoteOff(uint8_t channelNo) {
  modeMessage(channelNo, 0x7b);
}

#endif /* MIDI_COMPILE_SUBCOMMANDS */
