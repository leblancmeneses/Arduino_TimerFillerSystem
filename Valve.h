#ifndef VALVE_H
#define VALVE_H

#include "Arduino.h"

class Valve
{
  public:
    Valve(int pin, int shutOffValveTimeout);
    void enabled(boolean isEnabled);
    boolean isEnabled();
    void updateDigest();
  private:
    int _pin;
    int _shutOffValveTimeout;
    
    // Relies on a call to updateDigest() in the main loop().
    int _shutOffWhen;
    
    // Returned from isEnabled().
    boolean _isEnabled;
};

#endif
