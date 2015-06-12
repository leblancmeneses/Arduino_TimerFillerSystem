#include "Arduino.h"
#include "PhotoEye.h"

PhotoEye::PhotoEye(int pin, int steadyStateTimeout)
{
  _pin = pin;
  _lastMillisStatus = LOW;
  _lastMillis = millis();
  _steadyStateTimeout = steadyStateTimeout;
  _hasReachedSteadyState = false;
  pinMode(pin, INPUT);
}

int PhotoEye::getStatus(){
  return _lastMillisStatus;
}

boolean PhotoEye::hasReachedSteadyState(){
  return _hasReachedSteadyState;
}

void PhotoEye::updateDigest(){
  int currentStatus = digitalRead(_pin);
  
  if(_lastMillisStatus != currentStatus){
    _lastMillisStatus = currentStatus;
    _lastMillis = millis();
  }  
  
  if( (millis() - _lastMillis) > _steadyStateTimeout ) {  
    _hasReachedSteadyState = true;
  } else {
    _hasReachedSteadyState = false;
  }
}
