#ifndef VALVE_H
#define VALVE_H

#include "Arduino.h"

class Valve
{
  public:
    Valve(int pin);
    void setStatus(int isOn);
    int getStatus();
    void tick();
  private:
    int _pin;
    int _statusValue;
    // Relies on a call to tick() in the main loop().
    int _shutOffTimeoutMilliseconds;
};

#endif
