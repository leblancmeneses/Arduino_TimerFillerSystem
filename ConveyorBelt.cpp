#include "Arduino.h"
#include "ConveyorBelt.h"

ConveyorBelt::ConveyorBelt(int pin)
{
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void ConveyorBelt::enabled(boolean isExtended){
  digitalWrite(_pin, isExtended? HIGH:LOW);
}
