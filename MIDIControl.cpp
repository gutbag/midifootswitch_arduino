#include "MIDIControl.h"

MIDIControl::MIDIControl(const uint8_t aCC, const uint8_t anOffValue, const uint8_t anOnValue, DigitalInput& anInput, LED& anLED)
  : cc(aCC), offValue(anOffValue), onValue(anOnValue), input(anInput), led(anLED), currentOnState(false)
{
}

void MIDIControl::setup()
{
  off();
}

void MIDIControl::on()
{
  led.on();
  Serial1.write(0xb0 | 0); // channel 1
  Serial1.write(cc);
  Serial1.write(onValue);
}

void MIDIControl::off()
{
  led.off();
  Serial1.write(0xb0 | 0); // channel 1
  Serial1.write(cc);
  Serial1.write(offValue);
}

void MIDIControl::loop()
{
  if (input.read())
  {
    if (input.getState() == 0) // only act when the fsw is released
    {
      if (currentOnState) // turn off
      {
        off();
      }
      else // turn on
      {
        on();
      }
      currentOnState = not currentOnState;
    }
  }
}
