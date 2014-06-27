#ifndef __MORSE_H__
#define __MORSE_H__

#include <Arduino.h>

class Morse{
	private:
	void dot();
	void dash();
	void soundLetter(char letter);
	uint8_t dashlength;
	uint8_t inter;
	uint8_t lgap;
	uint8_t wgap;
	uint8_t dotlength;
	
	public:
	uint8_t buzzerPin;
	uint8_t ledPin;
	uint8_t tonefreq;
	Morse();
	void play(char thischar);
	void playMsg(char *stringa);
	void setDotLenght(uint8_t dotlength);
};
#endif
