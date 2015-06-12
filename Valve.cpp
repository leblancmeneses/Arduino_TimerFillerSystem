#include "Arduino.h"
#include "Valve.h"

Valve::Valve(int pin, int shutOffValveTimeout)
{
  _pin = pin;
  _shutOffValveTimeout = shutOffValveTimeout;
  
  pinMode(pin, OUTPUT);
}

void Valve::enabled(boolean isEnabled)
{  
  if(isEnabled == true){
    _shutOffWhen = _shutOffValveTimeout + millis();
  }
  _isEnabled = isEnabled;
  digitalWrite(_pin, (isEnabled == true? HIGH:LOW));
}

boolean Valve::isEnabled()
{  
  return _isEnabled;
}

void Valve::updateDigest()
{
  if (millis() > _shutOffWhen && _isEnabled == true) {
    enabled(false);
  }
}


