#ifndef MIDI_CLASS_H
#define MIDI_CLASS_H

#define MIDI_COMPILE_SUBCOMMANDS
#include <stdint.h>

class Stream;

class midiClass {
  public:
    midiClass(Stream *port);
    void keyOff(uint8_t channelNo, uint8_t keyNo, uint8_t velocity);
    void keyOn(uint8_t channelNo, uint8_t keyNo, uint8_t velocity);
    void controlChange(uint8_t channenNo, uint8_t data1, uint8_t data2);
    void modeMessage(uint8_t channelNo, uint8_t data);
    void programChange(uint8_t channelNo, uint8_t voiceNo);
    void channelAfterTouch(uint8_t channelNo, uint8_t data);
    void polyphonicAfterTouch(uint8_t channelNo, uint8_t keyNo, uint8_t data);
    void pitchBandChange(uint8_t channelNo, uint8_t msb, uint8_t lsb);

#ifdef MIDI_COMPILE_SUBCOMMANDS
    /* Control Change */
    void bankSelect(uint8_t channelNo, uint8_t msb, uint8_t lsb);
    void modulataion(uint8_t channelNo, uint8_t data);
    void mainVolume(uint8_t channelNo, uint8_t volume);
    
    /* Mode Message */
    void allSoundOff(uint8_t channelNo);
    void allNoteOff(uint8_t channelNo);
#endif /* MIDI_COMPILE_SUBCOMMANDS */

  protected:
    Stream *serialPort;
};

#endif /* MIDI_CLASS_H */
