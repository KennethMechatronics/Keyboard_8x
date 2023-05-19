/* Filnavn: Keyboard_8x.ino
  Versjon: V1.0
  Revisjon: 5 - 14.05.23 - Kenneth Paulsen 

  Program:
  Dette programmet er laget for å fungere som et macrokeyboard med macroer for nyttige tastetrykk i min nåværende jobb. 
  Macroene byttes med jevne mellomrom ut da en encoder for å bytte layout ennå ikke er loddet på kretskortet. 
*/
#include "Keyboard.h"


const int knapp1 = 2;
const int knapp2 = 3;
const int knapp3 = 4;
const int knapp4 = 5;
const int knapp5 = 6;
const int knapp6 = 7;
const int knapp7 = 8;
const int knapp8 = 9;

int dly = 10;


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for (int i = 2; i <= 9; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(LED_BUILTIN, OUTPUT);

  for (int j = 0; j <= 2; j++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(dly);
    digitalWrite(LED_BUILTIN, LOW);
    delay(dly);
  }

  delay(2000);
}

void loop() {

  if (digitalRead(knapp1) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    diagnose();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(knapp2) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    referanser();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(knapp3) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    notPrinted();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(knapp4) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    fett();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(knapp5) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    limeArbKode();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(knapp6) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    ramas();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(knapp7) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    smoreHenger();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  } else if (digitalRead(knapp8) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    knapp8Trykket();
    delay(300);
    digitalWrite(LED_BUILTIN, LOW);
  }
}


void diagnose() {  //DIAGNOSE
  Keyboard.write(KEY_F3);
  delay(dly);
  Keyboard.write(KEY_TAB);
  delay(dly);
  Keyboard.write(KEY_KP_PLUS);
  delay(dly);
  Keyboard.println("00");
  delay(dly);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(dly);
  Keyboard.write(KEY_RETURN);
  delay(dly);
  Keyboard.write(KEY_RETURN);
  delay(dly);
  Keyboard.write(KEY_ESC);
  digitalWrite(LED_BUILTIN, LOW);
}

void referanser() {  // Referanser
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(dly);
  Keyboard.write(KEY_LEFT_ARROW);
  for (int t = 0; t <= 7; t++) {
    Keyboard.write(KEY_TAB);
    delay(dly);
  }
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("c");
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(dly);
  for (int sT = 0; sT <= 7; sT++) {
    Keyboard.write(KEY_TAB);
    delay(dly);
  }
  Keyboard.releaseAll();
  Keyboard.write(KEY_RIGHT_ARROW);
  delay(dly);
  for (int t = 0; t <= 3; t++) {
    Keyboard.write(KEY_TAB);
    delay(dly);
  }
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("v");
  Keyboard.releaseAll();
  delay(dly);
  Keyboard.press(KEY_LEFT_SHIFT);
  for (int i = 0; i <= 3; i++) {
    Keyboard.write(KEY_TAB);
    delay(dly);
  }
  Keyboard.releaseAll();
  Keyboard.write(KEY_LEFT_ARROW);
  delay(dly);
  for (int i = 0; i <= 13; i++) {
    Keyboard.write(KEY_TAB);
    delay(dly);
  }



  digitalWrite(LED_BUILTIN, LOW);
}

void notPrinted() {  // Not printed
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.write(KEY_TAB);
  delay(dly);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(dly);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(dly);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(dly);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_RETURN);
  Keyboard.releaseAll();
  digitalWrite(LED_BUILTIN, LOW);
}

void fett() {  // 0,5 Fett
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.write(KEY_F2);
  delay(dly);
  Keyboard.println("1006529");
  delay(dly);
  Keyboard.println("0,5");
  delay(dly);
  Keyboard.write(KEY_ESC);
  digitalWrite(LED_BUILTIN, LOW);
}

void limeArbKode() {  // Lime inn arbeidskode
  Keyboard.write(KEY_F3);
  delay(dly);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(dly);
  Keyboard.print("v");
  Keyboard.releaseAll();
  delay(dly);
  Keyboard.write(KEY_RETURN);
  delay(dly);
  Keyboard.write(KEY_RETURN);
  delay(dly);
  Keyboard.write(KEY_RETURN);
  delay(dly);
  Keyboard.write(KEY_ESC);
}

void ramas() {  // Ramas
  Keyboard.press(KEY_LEFT_CTRL);
  delay(dly);
  Keyboard.print("j");
  Keyboard.releaseAll();
  delay(dly * 4);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(dly);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(dly);
  Keyboard.write(KEY_RETURN);
  delay(dly * 2);
  Keyboard.write(KEY_TAB);
  delay(dly);
  Keyboard.write(KEY_TAB);
  delay(dly * 2);
  Keyboard.println("62055");
  delay(dly * 2);
  Keyboard.write(KEY_RETURN);
}

void smoreHenger() { // Smøre henger  248	F8	ø
  Keyboard.write(KEY_F3);
  delay(dly);
  Keyboard.println("21008705");
  for (int t = 0; t <= 17; t++) {
    Keyboard.write(KEY_TAB);
    delay(dly);
  }
  Keyboard.write(KEY_BACKSPACE);
  delay(dly);
  Keyboard.print("Smøre henger");
  delay(dly);
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(dly);
   for (int t = 0; t <= 5; t++) {
    Keyboard.write(KEY_TAB);
    delay(dly);
  }
  Keyboard.releaseAll();
  delay(dly);
  Keyboard.println("Smøre henger");
  delay(dly);
  Keyboard.write(KEY_ESC);
  delay(dly);
  fett();
}

void knapp8Trykket() {
  delay(200);
  dly = dly * 2;
  Serial.println("Oker dly til " + String(dly));
  for (int i = 0; i <= 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(dly);
    digitalWrite(LED_BUILTIN, LOW);
    delay(dly);
  }
  if (dly >= 2000) {
    dly = 2;
  }
}







//
