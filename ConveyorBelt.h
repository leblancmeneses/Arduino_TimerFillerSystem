#ifndef CONVEYORBELT_H
#define CONVEYORBELT_H

#include "Arduino.h"

class ConveyorBelt
{
  public:
    ConveyorBelt(int pin);
    void enabled(boolean isEnabled);
  private:
    int _pin;
};

#endif
