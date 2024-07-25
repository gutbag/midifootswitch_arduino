#include "DigitalInput.h"

#define DEFAULT_DEBOUNCE_TIME 20


DigitalInput::DigitalInput(int aPin)
: pin(aPin), storedState(LOW), actualState(LOW), storedTime(0), debounceTime(DEFAULT_DEBOUNCE_TIME)
{
}
  
void DigitalInput::setup()
{
  pinMode(pin, INPUT_PULLUP);
  storedState = digitalRead(pin);
  storedTime = millis();
}
  
// returns true if state has changed
boolean DigitalInput::read()
{
  boolean stateChanged = false;
  
  int stateNow = digitalRead(pin);
  unsigned long  now = millis();
  if (stateNow != storedState)
  {
    storedState = stateNow;
    storedTime = now;
  }
  else // same state but has enough time elapsed?
  {
    if ((now - storedTime) >= debounceTime)
    {
      if (stateNow != actualState) // state change
      {
        stateChanged = true;
      }
      actualState = stateNow; // record new official state
    }
  }
  
  return stateChanged;
} 
  
int DigitalInput::getState()
{
  return actualState;
}

