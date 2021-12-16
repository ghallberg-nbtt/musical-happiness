/*
  Nightlight
  Copyright 2021 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/musical-happiness/blob/main/LICENSE
*/

// Define constant values
const int LIGHT = 0; // Photocell on Analog Pin 0
const int LED = 3; // Set pin 3 as LED
const int ON_OFF_LED = 13; // Use internal LED as on off indicator
const int BUTTON = 2; // On off button
const int high_level = 830;  // high light level
const int low_level = 440;  // low light level

// Define variables
int val = 0;  // Holds the analog reading from photocell
boolean previousButton = HIGH; // Variable containing the previous button state
boolean currentButton = HIGH; // Variable containing the current button state
boolean ledOn = false;  // The present state of the LED (on or off)

void setup()
{
  pinMode (ON_OFF_LED, OUTPUT); // on off LED
  pinMode (BUTTON, INPUT_PULLUP); // Button input
}

void loop()
{
  currentButton = digitalRead(BUTTON); // Read the switch state

  if (previousButton != currentButton)  // If switch pressed
  {
    delay(5);  // Wait 5ms
    currentButton = digitalRead(BUTTON);  // Read switch again
  }

  if (previousButton == HIGH && currentButton == LOW)  // Detect a button press
  {
    ledOn = !ledOn;  // Toggle the LED state on > off and off > on
  }
  previousButton = currentButton;  // Reset button value
  if (!ledOn) {
    digitalWrite (LED, LOW); // turn off LED
    digitalWrite (ON_OFF_LED, LOW); // turn off on/off indicator
  } else {
    digitalWrite (ON_OFF_LED, HIGH); // turn on on/off indicator
    val = analogRead(LIGHT);  // Read the light sensor
    val = map (val, low_level, high_level, 255, 0); // Map the ADC value to PWM value
    val = constrain (val, 0, 255);  // Constrain the values
    analogWrite (LED, val);
  }
}
