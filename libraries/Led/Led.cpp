/*
    LED turning off/on
*/

#include <Arduino.h>
#include "Led.h"

LED::LED(int p)
{
    pin = p;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, stav);
}

void LED::zapni()
{
    nastav(HIGH);
}

void LED::vypni()
{
    nastav(LOW);
}

void LED::prepni()
{
    nastav(!stav); //nastaví LED na obrácenou hodnotu (0->1, 1->0)
}

void LED::nastav(boolean s)
{
    stav = s;
    Serial.print("Nastavuji ");
    Serial.print(stav);
    Serial.print(" na pinu ");
    Serial.println(pin);
    digitalWrite(pin, stav);
}

boolean LED::vratStav()
{
    return stav;
}

BlikajiciLED::BlikajiciLED(int pin, int perioda): LED(pin)
{    
    _perioda = perioda;
    _posledniZmena = millis();
}

void BlikajiciLED::blikej()
{
    if(_posledniZmena + _perioda/2 <= millis()) {
        prepni();
        _posledniZmena = millis();
    }
}
