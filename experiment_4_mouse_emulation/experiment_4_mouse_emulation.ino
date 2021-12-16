/*
  Leonardo Mouse
  Copyright 2021 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/musical-happiness/blob/main/LICENSE
*/

#include <Mouse.h>

const int LEFT_BUTTON = 4;
const int MIDDLE_BUTTON = 3;
const int RIGHT_BUTTON = 2;
const int HORIZONTAL = A0;
const int VERTICAL = A1;

void setup() {
  Mouse.begin();
}

void loop() {
  int x = joystick(HORIZONTAL); //get horizontal movement
  int y = joystick(VERTICAL); //get vertical movement
  Mouse.move(x, y, 0); //move the mouse
  mouseButton (LEFT_BUTTON, MOUSE_LEFT); //Left button control
  mouseButton (MIDDLE_BUTTON, MOUSE_MIDDLE); //middle button control
  mouseButton (RIGHT_BUTTON, MOUSE_RIGHT); //middle button control
  delay (5); //this delay controls responsiveness
}

//Reads joystick values
int joystick(int axis) {
  int val  = analogRead(axis); //read the value
  val = map (val, 0, 1023, -10, 10); //map pot readings to mouse travel
  if (val <= 2 && val >= -2) {
    return 0; //dead zone to stop mouse jitter
  } else  {
    return val;
  }
}

//Read Button and issues mouse command
void mouseButton (int ioPin, char mouseCommand) {
  //button pressed
  if (digitalRead (ioPin) == LOW) {
    if (!Mouse.isPressed(mouseCommand)) {
      Mouse.press(mouseCommand);
    }
  } else {
    //button released
    if (Mouse.isPressed(mouseCommand))
    {
      Mouse.release (mouseCommand);
    }
  }
}
