/*
    Turn LED off/on repeatedly
*/

#include "Led.h"

LED L13(13);

void setup()
{
    Serial.begin(9600);
    L13.zapni();
    delay(1000);
    L13.vypni();
    delay(1000);
    for (int i = 0; i <= 10; i++) {
        L13.prepni();
        delay(500);
    }
    Serial.print("Led zustala ve stavu ");
    Serial.println(L13.vratStav());
}

void loop() {} 