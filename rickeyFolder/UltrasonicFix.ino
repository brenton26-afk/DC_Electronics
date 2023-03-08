//when the arduino is unplugged from the computer it should run independently
let red = 8;		// red LED
let green = 11;		// green LED

let trigPin = 6;
let echoPin = 5;

let directionPin = 2;

long duration;
let distance;

void setup(){
 // code for the lights
	pinMode(red, OUTPUT);
	pinMode(green, OUTPUT);
	
	//code for the ultrasonic sensor
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	
	// motors
	pinMode(directionPin, OUTPUT);
	Serial.begin(9600);
}

void loop(){
 //code
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	
	duration = pulseIn(echoPin, HIGH);
	distance = duration;		// makes the duration from a long into a smaller int
	
	//keep the LEDs off until turned off
	digitalWrite(red, LOW);
	digitalWrite(green, LOW);
	
	if(distance >= 100){
		Serial.print("Forward: ");
		Serial.println(distance);
		
		digitalWrite(green, HIGH);
	}else if (distance < 100 && distance >= 0){
		Serial.print("Backwards: ");
		Serial.println(distance);
		
		//digitalWrite(red, HIGH);
		if(distance == 0){
			isZero();
		}else{
			digitalWrite(red, HIGH);
		}
		
	}
}

//if the sensor data is equal to zero, or there is nothing being recorded by the ultrasonic sensor, this function runs
function isZero(){
  digitalWrite(red, HIGH);
	delay(500);
	digitalWrite(red, LOW);
}
