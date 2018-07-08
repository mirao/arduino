/*
  Blink

  Turns the LED on PIN 12 on, then off, repeatedly.
*/

// LED on PIN 12
const int ledExternal = 12;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pi as an output.
  pinMode(ledExternal, OUTPUT);
  Serial.begin(9600); // Don't forget to set the same rate in Baud Rate setting
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledExternal, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.println(digitalRead(ledExternal));
  delay(2000);                       // wait for 2 seconds
  digitalWrite(ledExternal, LOW);    // turn the LED off by making the voltage LOW
  Serial.println(digitalRead(ledExternal));
  delay(2000);                       // wait for 2 seconds
}
