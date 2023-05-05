/* Filnavn: Keyboard_8x
  Versjon: V1.0
  Revisjon: V1.0 - 04.05.23 - Første versjon - Kenneth Paulsen 

  Program:
*/
#include "Keyboard.h"
#include "HID.h"

const int knapp1 = 2;
const int knapp2 = 3;
const int knapp3 = 4;
const int knapp4 = 5;
const int knapp5 = 6;
const int knapp6 = 7;
const int knapp7 = 8;
const int knapp8 = 9;

unsigned long fortid;
int debounceDelay = 100;

int sepDel = 10;


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for (int i = 2; i <= 9; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(LED_BUILTIN, OUTPUT);

  for (int j = 0; j <= 2; j++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(sepDel);
    digitalWrite(LED_BUILTIN, LOW);
    delay(sepDel);
  }

  delay(2000);
}

void loop() {
  unsigned long naatid = millis();

  if (digitalRead(knapp1) == LOW) {
    knapp1Trykket();
    delay(300);
  } else if (digitalRead(knapp2) == LOW) {
    knapp2Trykket();
    delay(300);
  } else if (digitalRead(knapp3) == LOW) {
    knapp3Trykket();
    delay(300);
  } else if (digitalRead(knapp4) == LOW) {
    knapp4Trykket();
    delay(300);
  } else if (digitalRead(knapp5) == LOW) {
    knapp5Trykket();
    delay(300);
  } else if (digitalRead(knapp6) == LOW) {
    knapp6Trykket();
    delay(300);
  } else if (digitalRead(knapp7) == LOW) {
    knapp7Trykket();
    delay(300);
  } else if (digitalRead(knapp8) == LOW) {
    knapp8Trykket();
    delay(300);
  }
}


void knapp1Trykket() {  //DIAGNOSE
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("+00");
  Keyboard.write(KEY_F3);
  delay(sepDel);
  Keyboard.write(KEY_TAB);
  delay(sepDel);
  Keyboard.write(KEY_KP_PLUS);
  delay(sepDel);
  Keyboard.println("00");
  delay(sepDel);
  Keyboard.write(KEY_DOWN_ARROW);
  delay(sepDel);
  Keyboard.write(KEY_RETURN);
  delay(sepDel);
  Keyboard.write(KEY_RETURN);
  delay(sepDel);
  Keyboard.write(KEY_ESC);
  digitalWrite(LED_BUILTIN, LOW);
}

void knapp2Trykket() {  // Referanser
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(sepDel);
  Keyboard.write(KEY_LEFT_ARROW);
  for (int t = 0; t <= 7; t++) {
    Keyboard.write(KEY_TAB);
    delay(sepDel);
  }
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("c");
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_SHIFT);
  delay(sepDel);
  for (int sT = 0; sT <= 7; sT++) {
    Keyboard.write(KEY_TAB);
    delay(sepDel);
  }
  Keyboard.releaseAll();
  Keyboard.write(KEY_RIGHT_ARROW);
  delay(sepDel);
  for (int t = 0; t <= 3; t++) {
    Keyboard.write(KEY_TAB);
    delay(sepDel);
  }
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.print("v");
  Keyboard.releaseAll();
  digitalWrite(LED_BUILTIN, LOW);
}

void knapp3Trykket() {  // Not printed
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.write(KEY_TAB);
  delay(sepDel);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.press(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(KEY_RETURN);
  Keyboard.releaseAll();
  digitalWrite(LED_BUILTIN, LOW);
}

void knapp4Trykket() {  // 0,5 Fett
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.write(KEY_F2);
  delay(sepDel);
  Keyboard.println("1006529");
  delay(sepDel);
  Keyboard.println("0,5");
  delay(sepDel);
  Keyboard.write(KEY_ESC);
  digitalWrite(LED_BUILTIN, LOW);
}

void knapp5Trykket() {  // Lime inn arbeidskode
  Keyboard.write(KEY_F3);
  delay(sepDel);
  Keyboard.press(KEY_LEFT_CTRL);
  delay(sepDel);
  Keyboard.print("v");
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.write(KEY_RETURN);
  delay(sepDel);
  Keyboard.write(KEY_RETURN);
  delay(sepDel);
}

void knapp6Trykket() {  // Ramas
  Keyboard.press(KEY_LEFT_CTRL);
  delay(sepDel);
  Keyboard.print("j");
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(sepDel);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(sepDel);
  Keyboard.write(KEY_RETURN);
  delay(sepDel);
  Keyboard.write(KEY_TAB);
  delay(sepDel);
  Keyboard.write(KEY_TAB);
  delay(sepDel);
  Keyboard.println("62055");
  delay(sepDel);
  Keyboard.write(KEY_RETURN);
}

void knapp7Trykket() {
  // Noe kode
}

void knapp8Trykket() {
  delay(1000);
  sepDel = sepDel * 2;
  Serial.println("Oker sepDel til " + String(sepDel));
  for (int i = 0; i <= 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(sepDel);
    digitalWrite(LED_BUILTIN, LOW);
    delay(sepDel);
  }
  if (sepDel >= 2000) {
    sepDel = 2;
  }
}







//
