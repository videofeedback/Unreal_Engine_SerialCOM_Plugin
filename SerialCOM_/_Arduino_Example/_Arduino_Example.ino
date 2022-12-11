

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


void loop() {
  // read the sensor value:
  int sensorValue = analogRead(A0);
  // map the sensor range (0-1023) to a range of 1-100:
  int mappedValue = map(sensorValue, 0, 1023, 0, 100);
  // print the mapped value to the serial port:
  Serial.println(mappedValue);
  // wait a bit for the next reading:
  delay(100);
}
