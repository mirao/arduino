/*
    Blink by potentiometer voltage
    0 - 199 blinks LED1
    200 - 399 blinks LED1
    400 - 599 blinks LED1
    600 - 799 blinks LED1
    800 - 999 blinks LED1

    Pins:
    * A5 - potentiometer output
    * 2 - LED1 input
    * 3 - LED2 input
    * 4 - LED3 input
    * 5 - LED4 input
    * 6 - LED5 input

    Stuff:
    - 5x LED
    - 1x resistor 300 connected between all LED's output and ground   
*/

const byte potPin = A5;
const byte ledPins[] = {2, 3, 4, 5, 6};
byte ledCnt = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (byte i = 0; i < ledCnt; i++) {
    pinMode(ledPins[i], OUTPUT);
  } 
  pinMode(potPin, INPUT);
}

void loop() {
    int potV = analogRead(potPin);

    digitalWrite(ledPins[potV / 200], HIGH);
    delay(250);
    digitalWrite(ledPins[potV / 200], LOW);
    delay(250);
}