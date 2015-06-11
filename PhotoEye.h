#ifndef PHOTOEYE_H
#define PHOTOEYE_H

#include "Arduino.h"

class PhotoEye
{
  public:
    PhotoEye(int pin);
    int getStatus();
    void tick();
  private:
    int _pin;
    int _currentStatus;
    // Relies on a call to tick() in the main loop().
    int _blockedTimeoutMilliseconds;
};

#endif
