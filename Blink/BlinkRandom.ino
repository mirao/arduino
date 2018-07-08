/*
  Turns the builtin LED on/off for one second randomly, repeatedly
*/

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Don't forget to set the same rate in Baud Rate setting
  // Initialize random generator by random value so that repeating random() produces random sequence
  randomSeed(analogRead(0));
}

// The loop function runs over and over again forever
void loop() {
  int on = random(2); // LED on/off
  Serial.print("LED is ");
  if (on == 0) {
    digitalWrite(LED_BUILTIN, LOW);    // Turn the LED off by making the voltage LOW
    Serial.println("off");
  } else {
    digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on (HIGH is the voltage level)
    Serial.println("on");
  }
  delay(1000);                       // Wait for a second
}
