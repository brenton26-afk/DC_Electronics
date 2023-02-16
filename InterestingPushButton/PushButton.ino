// starter code for an interesting push button

int pin1 = 10;

void setup(){
	Serial.begin(9600);
	Serial.println("Hello World!");
	pinmode(pin1, OUTPUT);
}

void loop(){}
