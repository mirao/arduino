/*
  Turns the builtin LED on/off (and also LED on PIN 13) for one second randomly, repeatedly
*/

// LED state
struct led_state
{
  int voltage;
  const char *desc;
};

// Possible LED voltages/states
struct led_state led_states[] = {
  { LOW, "off" },
  { HIGH, "on" }
};

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
  int state = random(2); // LED on/off
  digitalWrite(LED_BUILTIN, led_states[state].voltage);    // Turn the LED on/off by making the voltage HIGH/LOW
  Serial.print("LED is ");
  Serial.println(led_states[state].desc); // Print LED state
  delay(1000);                       // Wait for a second
}
