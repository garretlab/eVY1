#ifndef eVY1_H
#define eVY1_H

#include "midiClass.h"
#include <stdint.h>

#define BANK_SELECT_NORMAL  0x00
#define BANK_SELECT_RAS     0x08
#define BANK_SELECT_DRUMKIT 0x7f

class Stream;

class eVY1 : public midiClass {
  public:
    eVY1(Stream *port);
    void eVocaloid(uint8_t mode, char *lyrics);
  private:
    Stream *serialPort;
};

#endif /* eVY1_H */

