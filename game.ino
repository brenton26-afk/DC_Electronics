
int button = 0;
int score = 0;

bool pressedB4 = false;

void setup() {
  // put your setup code here, to run once:
    
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(5,OUTPUT);
    
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
    if(pressedB4 == false){
      Serial.println("ON1");
      pressedB4 = true;
      score++;
      Serial.println(score);
    }
  }
  
  if(button == LOW){
    pressedB4 = false;
  }
  
}
