#ifndef eVY1_H
#define eVY1_H

#include "midiClass.h"
#include <stdint.h>

class Stream;

class eVY1 : public midiClass {
  public:
    eVY1(Stream *port);
    void eVocaloid(uint8_t mode, char *lyrics);
  private:
    Stream *serialPort;
};

#endif /* eVY1_H */

