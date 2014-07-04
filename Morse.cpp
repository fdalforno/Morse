#include<Morse.h>
#include<ctype.h>

const  byte _morsetab[] = {
    117, //ASCII 33 !   
    82,  //ASCII 34 "   
    1,   //ASCII 35 #   
    200, //ASCII 36 $   
    1,   //ASCII 37 %   
    34,  //ASCII 38 &   
    94,  //ASCII 39 '  
    45, //ASCII 40 (	
    109, //ASCII 41 )   
    1,   //ASCII 42 *   
    42,  //ASCII 43 +   
    115, //ASCII 44 ,   
    97,  //ASCII 45 -   
    106,  //ASCII 46 .  
    41,  //ASCII 47 /  
    63,  //ASCII 48 0
    62,  //ASCII 49 1
    60,  //ASCII 50 2
    56,  //ASCII 51 3
    48,  //ASCII 52 4
    32,  //ASCII 53 5
    33,  //ASCII 54 6
    35,  //ASCII 55 7
    39,  //ASCII 56 8
    47,  //ASCII 57 9
    71, //ASCII 58 :	
    85,  //ASCII 59 ;	
    1,   //ASCII 60 <
    49,  //ASCII 61 =
    1,   //ASCII 62 >
    76,  //ASCII 63 ?
    86,  //ASCII 64 @	
    6,   //ASCII 65 A
    17,  //ASCII 66 B
    21,  //ASCII 67 C
    9,   //ASCII 68 D
    2,   //ASCII 69 E
    20,  //ASCII 70 F
    11,  //ASCII 71 G
    16,  //ASCII 72 H
    4,   //ASCII 73 I
    30,  //ASCII 74 J
    13,  //ASCII 75 K
    18,  //ASCII 76 L
    7,   //ASCII 77 M
    5,   //ASCII 78 N
    15,  //ASCII 79 O
    22,  //ASCII 80 P
    27,  //ASCII 81 Q
    10,  //ASCII 82 R
    8,   //ASCII 83 S
    3,   //ASCII 84 T
    12,  //ASCII 85 U
    24,  //ASCII 86 V
    14,  //ASCII 87 W
    25,  //ASCII 88 X
    29,  //ASCII 89 Y
    19,  //ASCII 90 Z
    1,   //ASCII 91 [    
    64,   //ASCII 92 backslash    
    1,   //ASCII 93 ]   
    1,   //ASCII 94 ^
    108,  //ASCII 95 _    
    94,  //ASCII 96 '
};


Morse::Morse(){
	buzzerPin = 9;
	ledPin = 7;
	
	#ifdef __DEBUG_MORSE_H__
		Serial.begin(9600);
		while (!Serial);
	#endif
	
	pinMode(buzzerPin, OUTPUT);
	pinMode(ledPin, OUTPUT);
	
	tonefreq = 900;
	setDotLenght(70);
}

/**
 * Metodo per l'esecuzione di una lettera
 */
void Morse::play(char thischar){
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
	lgap = dotlength * 3; 
	wgap = dotlength * 7;
}

/**
 * Metodo per l'esecuzione del Punto
 */
void Morse::dot(){
  tone(buzzerPin, tonefreq);
  analogWrite(buzzerPin, 128);
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
 * Metodo per l'esecuzione di una lettera
 */
void Morse::soundLetter(char letter){
	byte index;
	byte value;

	if(letter == ' '){
		delay(wgap);
		return;
	}
	
	#ifdef __DEBUG_MORSE_H__
		Serial.print("Debug carattere : ");
		Serial.print(letter);
	#endif
	
	letter = toupper(letter);
	
	#ifdef __DEBUG_MORSE_H__
		Serial.print(" -> ");
		Serial.print(letter);	
		Serial.println("");
	#endif
	
	index = ((byte) letter) - 33;
	
	//Controllo overflow array
	int size = sizeof(_morsetab) / sizeof(byte);
	if(index >=  size){
		#ifdef __DEBUG_MORSE_H__
			Serial.println("Errore overflow !!");
		#endif
		return;
	}
	
	value = _morsetab[index];
	
	while (value != 1) {
		if (value & 1){
			dash();
		}else{
			dot();
		}
		
		value = value / 2;
	}
}

/**
 * Metodo per l'esecuzione di una frase
 */
void Morse::playMsg(char *stringa){
  while (*stringa){
    play(*stringa++);
  }
}


