

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

int sepDel = 400;


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  for (int i = 2; i <= 9; i++) {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(LED_BUILTIN, OUTPUT);

  for (int j = 0; j <= 9; j++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  delay(2000);
}

void loop() {
  unsigned long naatid = millis();

  if (digitalRead(knapp1) == LOW) {
    knapp1Trykket();
  } else if (digitalRead(knapp2) == LOW) {
    knapp2Trykket();
  } else if (digitalRead(knapp3) == LOW) {
    knapp3Trykket();
  } else if (digitalRead(knapp4) == LOW) {
    knapp4Trykket();
  } else if (digitalRead(knapp5) == LOW) {
    knapp5Trykket();
  } else if (digitalRead(knapp6) == LOW) {
    knapp6Trykket();
  } else if (digitalRead(knapp7) == LOW) {
    knapp7Trykket();
  } else if (digitalRead(knapp8) == LOW) {
    knapp8Trykket();
  }
}


void knapp1Trykket() {  //DIAGNOSE
  Serial.println("+00");
  Keyboard.press(KEY_F3);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.press(KEY_TAB);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.write(KEY_KP_PLUS);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.println("00");
  delay(sepDel);
  Keyboard.write(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.write(KEY_DOWN_ARROW);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.write(KEY_RETURN);
  Keyboard.releaseAll();
  delay(sepDel);
  Keyboard.write(KEY_ESC);
  Keyboard.releaseAll();
}

void knapp2Trykket() {
  // Noe kode
}

void knapp3Trykket() {
  // Noe kode
}

void knapp4Trykket() {
  // Noe kode
}

void knapp5Trykket() {
  // Noe kode
}

void knapp6Trykket() {
  // Noe kode
}

void knapp7Trykket() {
  // Noe kode
}

void knapp8Trykket() {
  delay(1000);
  sepDel = sepDel + 200;
  Serial.println("Oker sepDel til " + String(sepDel));
  for (int i = 0; i <= 2; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(sepDel);
    digitalWrite(LED_BUILTIN, LOW);
    delay(sepDel);
  }
  if (sepDel >= 2000) {
    sepDel = 200;
  }
}







//