int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

void setup() {
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 Serial.begin(9600);
 
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
 
  distance = duration * 0.034 / 2;

  int sensorValue = map(distance, 0, 70, 0, 255);
  Serial.print("Light: ");
  Serial.println(sensorValue);

  
  analogWrite(11, sensorValue);
  
  Serial.print("Distance: ");
  Serial.println(distance);
  //delay(500);
}
