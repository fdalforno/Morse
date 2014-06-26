#include <Morse.h>

Morse morse;

void setup(){
	morse = Morse();
}

void loop(){
	morse.play('S');
	morse.play('0');
	morse.play('S');
}