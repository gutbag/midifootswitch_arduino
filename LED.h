#ifndef LED_H
#define LED_H

#include "Arduino.h"

// numFlashes
#define CONTINUOUS 0

class LED
{
public:
	LED(const int aPin);
	~LED() {};
	void on();
	void off();
	void setDelay(const int aDelay);
	void flash(int num=CONTINUOUS);
	void setup();
	void loop();
private:
	void turnOn();
	void turnOff();
	enum Mode {STATIC, FLASHING};
	int pin;
	Mode mode;
	int delayValue;
	boolean isOn;
	int nextStateChange;
	int numFlashesRequired;
	int numFlashesDone;
	boolean isOnBeforeFlashing;
};

#endif


