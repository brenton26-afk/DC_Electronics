//rickey code

// green 9
// white 6 (trig pin)
// other green 5 (echo pin)

//leds should be pin 12 and 13

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
   pinMode(directionPin, OUTPUT);

   pinMode(12, OUTPUT);
   pinMode(13, OUTPUT);

 // Serial.begin(9600);
}

void loop() {

//  forward(1000);
//  backwards(1000);

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
  
 // Serial.println(distance);

  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
  if(sensorValue > 50){
    //forward(500);
    digitalWrite(12, HIGH);     //green LED
    delay(1000);
   // Serial.print("Forward: ");
   // Serial.println(sensorValue);
  }else if(sensorValue < 50){
    //backwards(500);
    digitalWrite(13, HIGH);    //red LED
  //  Serial.print("Backwards: ");
   // Serial.println(sensorValue);
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
