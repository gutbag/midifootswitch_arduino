#ifndef DIGITAL_INPUT_H
#define DIGITAL_INPUT_H

#include "Arduino.h"

class DigitalInput
{
public:
  DigitalInput(int aPin);
  
  void setup();
  void setDebounceTime(unsigned long ms);
  // returns true if state has changed
  boolean read();
  int getState();
  
private:
  int pin;
  int storedState;
  int actualState;
  unsigned long storedTime;
  unsigned long debounceTime;
};

#endif // DIGITAL_INPUT_H


