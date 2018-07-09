/*
  Turns the LED on PIN 3 and PIN 4 on/off, repeatedly.
  Connect the next stuff to see right voltages in console:
    * analog pin 3 with digital pin 3
    * analog pin 4 with digital pin 4
*/

// Digital pins where LEDs are attached
const int pinLed1 = 3;
const int pinLed2 = 4;

const double voltageDiv = 5.0 / 1024;

/*
 * Print voltage on given pin
 */
void printVoltage(int pin) {
  Serial.println(String("LED PIN " + String(pin) + ": " + String(analogRead(pin) * voltageDiv) + "V"));
}

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pi as an output.
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  Serial.println("Voltages:");
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pinLed1, HIGH);   // turn the 1st LED on
  printVoltage(pinLed1);
  delay(1000);                 
  digitalWrite(pinLed1, LOW);   // turn the 1st LED off
  printVoltage(pinLed1);
  digitalWrite(pinLed2, HIGH);   // turn the 2nd LED on
  printVoltage(pinLed2);
  delay(1000);
  digitalWrite(pinLed2, LOW);   // turn the 2nd LED off
  printVoltage(pinLed2);
}
