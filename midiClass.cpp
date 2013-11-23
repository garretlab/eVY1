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
void midiClass::noteOff(uint8_t channelNo, uint8_t keyNo, uint8_t velocity) {
  serialPort->write(0x80 | channelNo);
  serialPort->write(keyNo);
  serialPort->write(velocity);
}

void midiClass::noteOn(uint8_t channelNo, uint8_t keyNo, uint8_t velocity) {
  serialPort->write(0x90 | channelNo);
  serialPort->write(keyNo);
  serialPort->write(velocity);
}

void midiClass::polyphonicKeyPressure(uint8_t channelNo, uint8_t keyNo, uint8_t data) {
  serialPort->write(0xa0 | channelNo);
  serialPort->write(keyNo);
  serialPort->write(data);
}

void midiClass::controlChange(uint8_t channelNo, uint8_t data1, uint8_t data2) {
  serialPort->write(0xb0 | channelNo);
  serialPort->write(data1);
  serialPort->write(data2);
}

void midiClass::programChange(uint8_t channelNo, uint8_t voiceNo) {
  serialPort->write(0xc0 | channelNo);
  serialPort->write(voiceNo);
}

void midiClass::channelPressure(uint8_t channelNo, uint8_t data) {
  serialPort->write(0xd0 | channelNo);
  serialPort->write(data);
}

void midiClass::pitchBend(uint8_t channelNo, uint8_t msb, uint8_t lsb) {
  serialPort->write(0xe0 | channelNo);
  serialPort->write(lsb);
  serialPort->write(msb);
}

