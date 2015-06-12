#ifndef PHOTOEYE_H
#define PHOTOEYE_H

#include "Arduino.h"

class PhotoEye
{
  public:
    PhotoEye(int pin, int steadyStateTimeout);
    int getStatus();
    boolean hasReachedSteadyState();
    void updateDigest();
  private:
    int _pin;
    int _lastMillisStatus;
    int _lastMillis;
    boolean _hasReachedSteadyState;
    
    // Relies on a call to updateDigest() in the main loop().
    int _steadyStateTimeout;
};

#endif
