
int button = 0;
int score = 0;

void setup() {
  // put your setup code here, to run once:
    
    //pinMode(,OUTPUT);
   // pinMode(,OUTPUT);
    //pinMode(,OUTPUT);
    
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(2, INPUT);
    Serial.begin(19200);
    Serial.println("Hello World");
    
}

void loop() {
  // put your main code here, to run repeatedly:
  button = digitalRead(2);
  if(button == HIGH){
    Serial.println("ON1");
    //button = 0;
  }
}
