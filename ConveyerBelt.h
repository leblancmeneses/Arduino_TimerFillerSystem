#ifndef CONVEYERBELT_H
#define CONVEYERBELT_H

#include "Arduino.h"

class ConveyerBelt
{
  public:
    ConveyerBelt(int pin);
    void setStatus(int isOn);
    int getStatus();
  private:
    int _pin;
};

#endif
