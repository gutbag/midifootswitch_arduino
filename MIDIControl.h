#ifndef MIDI_CONTROL_H
#define MIDI_CONTROL_H

#include "Arduino.h"
#include "DigitalInput.h"
#include "LED.h"

/**
 * A feature controlled by a MIDI Control Change message.
 */
class MIDIControl
{
public:
	MIDIControl(const uint8_t aCC, const uint8_t anOffValue, const uint8_t anOnValue, DigitalInput& anInput, LED& anLED);
	~MIDIControl() {};
	void setup();
	void loop();

private:
  uint8_t cc;
  uint8_t offValue;
  uint8_t onValue;
  DigitalInput& input;
  LED& led;
  boolean currentOnState;

  void on();
  void off();
};

#endif
