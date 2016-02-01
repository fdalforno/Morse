#include <Morse.h>

#define NUM_RIPETIZIONI 3
#define PAUSA 60 * 1000
#define PAUSA_INTERMEDIA 2 * 1000

Morse morse;

void setup(){
	
}

void loop(){
  for(int i = 0; i < NUM_RIPETIZIONI; i++){
	  morse.playMsg("CQ CQ CQ IZ3OHR/B JN 55LJ ARIVERONAEST BEACON FOR CW LEARNING PROJECT 73 BYE");
	  delay(PAUSA_INTERMEDIA);
  }
  
  delay(PAUSA);
}
