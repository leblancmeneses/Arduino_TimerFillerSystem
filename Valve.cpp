#include "Arduino.h"
#include "Valve.h"

Valve::Valve(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  
  // Load from EPROM
  _shutOffTimeoutMilliseconds = 1000;
}

//https://github.com/adafruit/Adafruit-BMP085-Library
//https://github.com/aron-bordin/ArduinoTimerObject
// http://www.arduino.cc/en/Hacking/LibraryTutorial
void Valve::setStatus(int isOn)
{
  _statusValue = isOn;
  if(isOn == HIGH){
    _shutOffTimeoutMilliseconds = 1000 * _shutOffTimeoutMilliseconds;
  }
  digitalWrite(_pin, _statusValue);
}

class Valve
{
  public:

    void setStatus();
    int getStatus();
    void tick();
  private:
    int _pin;
    // Relies on a call to tick() in the main loop().
    int _shutOffTimeoutMilliseconds;
};

