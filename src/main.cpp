#include <Arduino.h>


void setup() {
    pinMode(PB2, OUTPUT);
    pinMode(PB5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PB2, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);   
  digitalWrite(PB5, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(500);   
  digitalWrite(PB2, LOW);   // turn the LED off by making the voltage LOW
  delay(500);
  digitalWrite(PB5, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
}
