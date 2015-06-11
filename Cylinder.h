#ifndef CYLINDER_H
#define CYLINDER_H

#include "Arduino.h"

class Cylinder
{
  public:
    Cylinder(int extendPin, int retractPin);
    void setStatus(int isExtended);
    int getStatus();
  private:
    int _extendPin;
    int _retractPin;
};

#endif
