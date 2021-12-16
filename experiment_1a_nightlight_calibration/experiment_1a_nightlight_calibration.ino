/*
  Nightlight Calibration
  Copyright 2021 Gary Hallberg
  Licensed under MIT https://github.com/ghallberg-nbtt/musical-happiness/blob/main/LICENSE
*/

// Define constant values
const int LIGHT=0;  // Photocell on Analog Pin 0

// Define variables
int val = 0;  // Holds the analog reading from photocell

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(LIGHT);  // Read the light sensor
  Serial.println(val);
  delay (500);
}
