/*
  Receives numbers from serial line and prints them
  E.g.:
  * Send this text to serial port:
    2;3 560;01
  * Output:
    Buffer: 10 bytes
    Received number: 2
    Buffer: 9 bytes
    Received number: 3560
    Buffer: 3 bytes
    Received number: 1
    Buffer: 0 bytes
*/

void setup(){
  Serial.begin(9600);
  Serial.println("Starting communication");
}

void loop(){
  Serial.print("Buffer: ");
  Serial.print(Serial.available());
  Serial.println(" bytes");
  if (Serial.available() > 0) {
    Serial.print("Received number: ");
    Serial.println(Serial.parseInt(SKIP_ALL, ' ')); // Space is thousand delimiter
  }
  delay(1000);
}