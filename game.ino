
int button = 0;
int score = 0;
int theTime = 6;

bool canStart = false;
bool pressedB4 = false;

void setup() {
  // put your setup code here, to run once:
    
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(4,OUTPUT);
    
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(2, INPUT);
    Serial.begin(9600);
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
  } else if(button == LOW){
    pressedB4 = false;
  }

  if(score == 1){
    canStart = true;
  }else{
    canStart = false;
  }
  
  if(canStart == true){
    gameStart();
    canStart = false;
  }


  
}

void gameStart(){
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);

    if(score >= 1){
  while(theTime >= 0){
    if(theTime < 5){
      digitalWrite(7, LOW);
    }
    if(theTime < 3){
      digitalWrite(6, LOW);
      Serial.println("Something");
    }
    if(theTime < 1){
      digitalWrite(4, LOW);
      Serial.println("it should work");
    }
    delay(1000);
    theTime = theTime - 1;
  }
  }
}
