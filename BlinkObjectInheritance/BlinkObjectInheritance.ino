/*
    Turn LED off/on repeatedly
*/

#include "Led.h"

BlikajiciLED L9(9, 500);
BlikajiciLED L10(10, 1500);

void setup() {
    Serial.begin(9600);
}

void loop() {
    L9.blikej();
    L10.blikej();
} 