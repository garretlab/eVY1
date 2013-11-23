#ifndef MIDI_CLASS_H
#define MIDI_CLASS_H

#include <stdint.h>


class Stream;

class midiClass {
  public:
    midiClass(Stream *port);
    void noteOff(uint8_t channelNo, uint8_t keyNo, uint8_t velocity);
    void noteOn(uint8_t channelNo, uint8_t keyNo, uint8_t velocity);
    void polyphonicKeyPressure(uint8_t channelNo, uint8_t keyNo, uint8_t data);
    void controlChange(uint8_t channenNo, uint8_t data1, uint8_t data2);
    void programChange(uint8_t channelNo, uint8_t voiceNo);
    void channelPressure(uint8_t channelNo, uint8_t data);
    void pitchBend(uint8_t channelNo, uint8_t msb, uint8_t lsb);

  protected:
    Stream *serialPort;
};

#endif /* MIDI_CLASS_H */
