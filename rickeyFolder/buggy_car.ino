//rickey code
int directionPin = 2;
int speedPin = 3;

int trigPin = 5;
int echoPin = 4;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  Serial.begin(9600);
}

void loop() {
  pinMode(directionPin, OUTPUT);

//   forward(5000);
//   backwards(5000);

// ultrasonic code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
 
  distance = duration * 0.034 / 2;

  int sensorValue = map(distance, 0, 1000, 0, 100);
  //int sensorValue = distance;
  //Serial.print("Light: ");
  Serial.println(sensorValue);


  if(sensorValue >= 800){
    //forward(5);
  }else if(sensorValue < 800){
   //backwards(5);
  }

}

void forward(int t){
  analogWrite(speedPin, 255);
  digitalWrite(directionPin, HIGH);
  delay(t);
}

void backwards(int t){
  analogWrite(speedPin, 255);
  digitalWrite(directionPin, LOW);
  delay(t);
}
