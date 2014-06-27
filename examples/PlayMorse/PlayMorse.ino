#include <Morse.h>

Morse morse;

void setup(){
  morse = Morse();
}

void loop(){
  morse.playMsg("CQ CQ CQ IZ3OHR/B JN 55LJ ARIVERONAEST BEACON FOR CW LEARNING PROJECT 73 BYE");
}