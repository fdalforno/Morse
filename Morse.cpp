#include<Morse.h>
Morse::Morse(){
	buzzerPin = 9;
	ledPin = 7;
	
	pinMode(buzzerPin, OUTPUT);
	pinMode(ledPin, OUTPUT);
	
	tonefreq = 900;
	setDotLenght(70);
}

/**
 * Metodo per l'esecuzione di una lettera
 */
void Morse::play(char thischar){

	if (thischar>='a' && thischar<='z'){
		thischar = thischar - 32; 
	}

	if(!((thischar>64 && thischar<91) || (thischar>47 && thischar<59) || thischar == 32 || thischar == 63 || thischar == 59 || thischar == 44)){
		thischar = ' ';
	}
	
	soundLetter(thischar);
    delay(lgap);
}

/**
 * Imposto la lunghezza in millisecondi del punto
 * e calcolo la lunghezza delle pause collegate
 * questo è il metodo per calcolare la velocità del messaggio
 */
void Morse::setDotLenght(uint8_t _dotlength){
	dotlength = _dotlength;
	dashlength = dotlength * 3;
	inter = dotlength;
	lgap = dotlength * 2; 
	wgap = dotlength * 4;
}

/**
 * Metodo per l'esecuzione del Punto
 */
void Morse::dot(){
  tone(buzzerPin, tonefreq);
  digitalWrite(ledPin, HIGH);
  delay(dotlength);
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);
  delay(inter);
}

/**
 * Metodo per l'esecuzione della linea
 */
void Morse::dash(){
  tone(buzzerPin, tonefreq);
  digitalWrite(ledPin, HIGH);
  delay(dashlength);
  noTone(buzzerPin);
  digitalWrite(ledPin, LOW);
  delay(inter);
}

/**
 * Metodo per l'esecuzione di una lettera in UPPERCASE
 */
void Morse::soundLetter(char letter){
  switch(letter){
  case 'E':
    dot();
    return;
  case 'T':
    dash();
    return;
  case 'A':
    dot();
    dash();
    return;
  case 'O':
    dash();
    dash();
    dash();
    return;
  case 'I':
    dot();
    dot();
    return;
  case 'N':
    dash();
    dot();
    return;
  case 'S':
    dot();
    dot();
    dot();
    return;
  case 'H':
    dot();
    dot();
    dot();
    dot();
    return;
  case 'R':
    dot();
    dash();
    dot();
    return;
  case 'D':
    dash();
    dot();
    dot();
    return;
  case 'L':
    dot();
    dash();
    dot();
    dot();
    return;
  case 'C':
    dash();
    dot();
    dash();
    dot();
    return;
  case 'U':
    dot();
    dot();
    dash();
    return;
  case 'M':
    dash();
    dash();
    return;
  case 'W':
    dot();
    dash();
    dash();
    return;
  case 'F':
    dot();
    dot();
    dash();
    dot();
    return;
  case 'G':
    dash();
    dash();
    dot();
    return;
  case 'Y':
    dash();
    dot();
    dash();
    dash();
    return;
  case 'P':
    dot();
    dash();
    dash();
    dot();
    return;
  case 'B':
    dash();
    dot();
    dot();
    dot();
    return;
  case 'V':
    dot();
    dot();
    dot();
    dash();
    return;
  case 'K':
    dash();
    dot();
    dash();
    return;
  case 'J':
    dot();
    dash();
    dash();
    dash();
    return;
  case 'X':
    dash();
    dot();
    dot();
    dash();
    return;
  case 'Q':
    dash();
    dash();
    dot();
    dash();
    return;
  case 'Z':
    dash();
    dash();
    dot();
    dot();
    return;
  case '1':
    dot();
    dash();
    dash();
    dash();
    dash();
    dash();
    return;
  case '2':
    dot();
    dot();
    dash();
    dash();
    dash();
    return;
  case '3':
    dot();
    dot();
    dot();
    dash();
    dash();
    return;
  case '4':
    dot();
    dot();
    dot();
    dot();
    dash();
    return;
  case '5':
    dot();
    dot();
    dot();
    dot();
    dot();
    return;
  case '6':
    dash();
    dot();
    dot();
    dot();
    dot();
    return;
  case '7':
    dash();
    dash();
    dot();
    dot();
    dot();
    return;
  case '8':
    dash();
    dash();
    dash();
    dot();
    dot();
    return;
  case '9':
    dash();
    dash();
    dash();
    dash();
    dot();
    return;
  case '0':
    dash();
    dash();
    dash();
    dash();
    dash();
    return;
   case '?':
    dot();
    dot();
    dash();
    dash();
    dot();
    dot();
    return;
  case ':':
    dash();
    dash();
    dash();
    dot();
    dot();
    dot();
    return;
  case ',':
    dash();
    dash();
    dot();
    dot();
    dash();
    dash();
    return;
  case ' ':
    delay(wgap);
    return;
  }
}