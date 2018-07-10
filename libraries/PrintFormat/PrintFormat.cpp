/*
    Formatted printing of stuff like voltage into console
*/

#include "Arduino.h"
#include "PrintFormat.h"

/**
 * Print voltage on given pin
 */
void PrintFormat::printVoltage(int pin) {
  Serial.println(String("LED PIN " + String(pin) + ": " + String(analogRead(pin) * _voltageDiv) + "V"));
}