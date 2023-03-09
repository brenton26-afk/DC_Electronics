// rickey code


// left wheels
int leftD = 4;
int leftSpeed = 5;

// right wheels
int rightD = 2;
int rightSpeed = 6;

int pwr = HIGH;     // power to the wheels 

// ultrasonic sensor
int trigPin = 12;
int echoPin = 13;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  Serial.println("Hello World!");

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

  
  pinMode(A0, OUTPUT);
  // start of code indicator light
  digitalWrite(A0, HIGH);
  delay(500);
  digitalWrite(A0, LOW);

  // pinMode wheels
  pinMode(leftD, OUTPUT);
  pinMode(leftSpeed, OUTPUT);
  pinMode(rightD, OUTPUT);
  pinMode(rightSpeed, OUTPUT);
  
  //digitalWrite(rightD, HIGH);    // low is backwards high is forwards
  //digitalWrite(rightSpeed, pwr);
  //digitalWrite(leftD, LOW);    // low is backwards high is forwards
  //digitalWrite(leftSpeed, pwr);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
 
  distance = duration * 0.034 / 2;

  Serial.print("distance: ");
  Serial.println(distance);

  if(distance >= 40){
    forward();
  }else if( distance < 40){
    backward();
  }

  
  }

// function to decide on what direction to go
void forward(){
  digitalWrite(rightSpeed, HIGH);
  digitalWrite(leftSpeed, HIGH);
  digitalWrite(rightD, HIGH);
  digitalWrite(leftD, HIGH);
}

void backward(){
  digitalWrite(rightSpeed, HIGH);
  digitalWrite(leftSpeed, HIGH);
  digitalWrite(rightD, LOW);
  digitalWrite(leftD, LOW);
}
