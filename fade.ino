
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));
  int data = analogRead(A0);
  int sensorValue = map(data, 0, 1023, 0, 255);
  delay(250);
  Serial.print("Sensor val: ");
  Serial.println(sensorValue);
  analogWrite(10, sensorValue);

}
