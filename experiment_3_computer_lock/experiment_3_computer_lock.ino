/*
  Light Controlled Computer Lock
  Copyright 2021 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/musical-happiness/blob/main/LICENSE
*/

#include <Keyboard.h>

const int LDR = A0; //LDR input
const int THRESHOLD = 400; //Light threshold

void setup() {
  Keyboard.begin();
}

void loop() {
  int lightLevel = analogRead (LDR); //Read light level
  if (lightLevel < 400) {
    //lock computer
    Keyboard.press (KEY_LEFT_GUI);
    Keyboard.press ('l');
    delay (100);
    Keyboard.releaseAll();
  }
}
