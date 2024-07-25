#include "LED.h"

#define DEFAULT_DELAY 1000

LED::LED(const int aPin)
: pin(aPin), mode(STATIC), delayValue(DEFAULT_DELAY), numFlashesRequired(0), numFlashesDone(0), isOnBeforeFlashing(false)
{
	nextStateChange = millis() + delayValue;
}

void LED::on()
{
	turnOn();
	mode = STATIC;
}

void LED::off()
{
	turnOff();
	mode = STATIC;
}

void LED::turnOn()
{
	digitalWrite(pin, HIGH);
	isOn = true;
}

void LED::turnOff()
{
	digitalWrite(pin, LOW);
	isOn = false;
}

void LED::flash(int num /*=CONTINUOUS*/)
{
	if (mode != FLASHING) // starting to flash
	{
		isOnBeforeFlashing = isOn; // need to restore this after flashing
                if (isOn)
                {
		  turnOff(); // intially off
                }
                else
                  turnOn();
                  
		nextStateChange = millis() + delayValue;
		numFlashesDone = 0;
		mode = FLASHING;
	}

	// update the number of flashes required 
	numFlashesRequired = num;
}

void LED::setDelay(const int aDelay)
{
	delayValue = aDelay;
}

void LED::setup()
{
	pinMode(pin, OUTPUT);	
	off();
}

void LED::loop()
{
	if (mode == FLASHING)
	{
		int now = millis();
		if (now > nextStateChange)
		{
			if (isOn)
			{
				turnOff();
				if (numFlashesRequired != CONTINUOUS)
				{
					numFlashesDone++;
					if (numFlashesDone >= numFlashesRequired)
					{
						if (isOnBeforeFlashing)
							on();
						else
							off();
					}
				}
			}
			else
				turnOn();
			nextStateChange = now + delayValue;
		}
	}
}


