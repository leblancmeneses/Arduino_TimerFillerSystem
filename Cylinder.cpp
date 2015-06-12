#include "Arduino.h"
#include "Cylinder.h"

Cylinder::Cylinder(int extendPin, int retractPin)
{
  _extendPin = extendPin;
  _retractPin = retractPin;
  
  pinMode(_extendPin, OUTPUT);
  pinMode(_retractPin, OUTPUT);
}

void Cylinder::extend(boolean isExtended){
  if(isExtended){
    digitalWrite(_extendPin,  HIGH);
    digitalWrite(_retractPin, LOW);
  } else{
    digitalWrite(_extendPin,  LOW);
    digitalWrite(_retractPin, HIGH);
  }
}
