//rickey code

// green 9
// white 6 (trig pin)
// other green 5 (echo pin)

int directionPin = 2;
int speedPin = 3;

int trigPin = 6;
int echoPin = 5;

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

//  forward(5000);
//  backwards(5000);

// ultrasonic code
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 // inspect pluseIn 
 //could be source of problem
  duration = pulseIn(echoPin, HIGH);
 
  // distance = duration * 0.034 / 2;
  distance = duration;

  int sensorValue = map(distance, 0, 15000, 0, 500);
  //int sensorValue = distance;
  //Serial.print("Light: ");
  Serial.println(sensorValue);
 // Serial.println(distance);


  if(sensorValue >= 100){
    forward(5);
  }else if(sensorValue < 100){
    backwards(5);
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
