#ifndef CYLINDER_H
#define CYLINDER_H

#include "Arduino.h"

class Cylinder
{
  public:
    Cylinder(int extendPin, int retractPin);
    void extend(boolean isExtended);
  private:
    int _extendPin;
    int _retractPin;
};

#endif
