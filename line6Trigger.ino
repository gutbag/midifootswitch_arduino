#include "LED.h"
#include "DigitalInput.h"
#include "MIDIControl.h"

#define LED_1 D0
#define LED_2 D10
#define LED_3 D9

#define FSW_1 D5
#define FSW_2 D4
#define FSW_3 D3

DigitalInput fsw1Input(FSW_1);
DigitalInput fsw2Input(FSW_2);
DigitalInput fsw3Input(FSW_3);

LED led1(LED_1);
LED led2(LED_2);
LED led3(LED_3);

MIDIControl fsw1Control(25, 0, 127, fsw1Input, led1);
MIDIControl fsw2Control(50, 0, 127, fsw2Input, led2);
MIDIControl fsw3Control(28, 0, 127, fsw3Input, led3);

void setup() 
{                
  Serial1.begin(31250);

  led1.setup();
  led1.off();
  led2.setup();
  led2.off();
  led3.setup();
  led3.off();

  fsw1Input.setup();
  fsw2Input.setup();
  fsw3Input.setup();

  fsw1Control.setup();
  fsw2Control.setup();
  fsw3Control.setup();

  // flash LEDs to confirm power
  led1.on();
  led2.on();
  led3.on();
  delay(2000);
  led1.off();
  led2.off();
  led3.off();

  // a bit more flashing
  for (int i=0; i<3; i++)
  {
    led1.on();
    delay(100);
    led1.off();
    led2.on();
    delay(100);
    led2.off();
    led3.on();
    delay(100);
    led3.off();
  }
}

void loop()
{
  led1.loop();
  led2.loop();
  led3.loop();

  fsw1Control.loop();
  fsw2Control.loop();
  fsw3Control.loop();
}
