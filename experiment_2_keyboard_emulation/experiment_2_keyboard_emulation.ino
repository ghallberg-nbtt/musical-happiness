/*
  Water Level Monitor
  Copyright 2021 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/musical-happiness/blob/main/LICENSE
*/

#include <Keyboard.h>

const int BUTTON = 2; //Pushbutton
const int SENSOR = A0; //Water level sensor and keyboard emulation
const int ON_OFF_LED = 13; // Use internal LED as on off indicator

boolean previousButton = HIGH; // Variable containing the previous button state
boolean currentButton = HIGH; // Variable containing the current button state
boolean ledOn = false;  //Sample collection on and off + LED
int sampleNumber; //A counter for the sample number

void setup() {
  pinMode (BUTTON, INPUT_PULLUP);
  Keyboard.begin(); //start keyboard emulation
}

void loop() {
  currentButton = digitalRead(BUTTON); //Read the switch state

  if (previousButton != currentButton)  //If switch pressed
  {
    delay(5);  // Wait 5ms
    currentButton = digitalRead(BUTTON);  //Read switch again
  }

  if (previousButton == HIGH && currentButton == LOW)  //Detect a button press
  {
    ledOn = !ledOn;  //Toggle the LED state on > off and off > on
  }

  if (ledOn) {
    //Collect samples
    digitalWrite (ON_OFF_LED, HIGH); //Turn on LED
    if (millis() % 2000 == 0) { //Collect every 2 seconds
      int waterLevel = analogRead(SENSOR); //Read water level sensor
      Keyboard.print (sampleNumber); //Print index
      Keyboard.print (","); //Print a comma
      Keyboard.println(waterLevel); //Print the water level and newline
      sampleNumber++; //increment the sample number
    }
  }
  else {
    //Turn off sampling
    digitalWrite (ON_OFF_LED, LOW); //Turn off
  }
}
