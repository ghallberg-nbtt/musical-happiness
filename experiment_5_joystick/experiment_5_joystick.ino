/*
  Joystick using Keyboard Emulation
  Copyright 2021 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/musical-happiness/blob/main/LICENSE
*/

#include <Keyboard.h>

const int BUTTON = 2;
const int HORIZONTAL = A0;
const int VERTICAL = A1;

int x, y;
int sw;

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  int x = analogRead(HORIZONTAL); //get horizontal movement
  if (x == 1023)// fully right
  {
    Serial.println("Right");
    Keyboard.press(215); //right arrow
  }
  else
  {
    Keyboard.release(215);  //release the key
  }

  x = analogRead(HORIZONTAL); //get horizontal movement
  if (x == 0) // fully left
  {
    Serial.println("Left");
    Keyboard.press(216); //left arrow
  }
  else
  {
    Keyboard.release(216);  //release the key
  }

  y = analogRead(VERTICAL); //get vertical movement
  if (y == 0) // fully up
  {
    Serial.println("Up");
    Keyboard.press(218); //up arrow
  }
  else
  {
    Keyboard.release(218);  //release the key
  }

  y = analogRead(VERTICAL);
  if (y == 1023) //fully down
  {
    Serial.println("Down");
    Keyboard.press(217); //down arrow
  }
  else
  {
    Keyboard.release(217);  //release the key
  }

  sw = digitalRead (BUTTON); //see if switch pressed

  if (sw == 0) //switch pressed
  {
    Serial.println("Space bar");
    Keyboard.println(" "); //space bar
  }

  delay (200); //this delay controls responsiveness
}
