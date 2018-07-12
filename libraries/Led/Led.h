/*
    LED turning off/on
*/

#include <Arduino.h>

class LED
{
    private:
        int pin;
        boolean stav = LOW; //výchozí stav LED je vypnuto
        void nastav(boolean);
    public:
        LED(int);
        void zapni();
        void vypni();
        void prepni();
        boolean vratStav();
};

class BlikajiciLED: public LED
{
    private:
        int _perioda = 0;
        unsigned long _posledniZmena = 0;
    public:
        BlikajiciLED(int, int);
        void blikej();
};