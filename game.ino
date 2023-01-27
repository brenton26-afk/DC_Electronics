
int button = 0;
int score = 0;
int theTime = 6;

bool canStart = true;
bool pressedB4 = false;
bool start = false;

void setup() {
  // put your setup code here, to run once:
    
    pinMode(7,OUTPUT);    //red light
    pinMode(6,OUTPUT);    //red light
    pinMode(4,OUTPUT);    //red light
    
    pinMode(12, OUTPUT);    //game lights
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(2, INPUT);    //button
    Serial.begin(9600);
    Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  button = digitalRead(2);
  
  if(button == HIGH && pressedB4 == false){     //if button is on
      //Serial.println("ON1");
      pressedB4 = true;
      
        if(start == true){
          score++;
          Serial.println(score);
        }
    
//start the game with by pressing the button once
      if(canStart == true){
          canStart == false;
          gameStart();
        }
      
        //button on ^^
  } else if(button == LOW){
    pressedB4 = false;
  }
    
  
// reset the score and the time when the time is up 
if(theTime == 0){
  score = 0;
  theTime = 6;
  Serial.println("All done: ");
  Serial.println(score);
}
  
// add the if statements that turn on the score lights as the button is pressed more times. 
	
}

void gameStart(){
  
  //turn on the game lights to start
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(1000);
  //3,2,1 countdown
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(12, HIGH);
  delay(1000);
  
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  start = true;
  
  //just to break apart the time it takes for this to run
  //delete the delay when the game is done
  delay(500);
    
  
  //the timer lights turn on
  
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(4, HIGH);

 //turns of manually
    
    delay(2000);
    theTime = theTime - 2;
    digitalWrite(7, LOW);
    delay(2000);
    theTime = theTime - 2;
    digitalWrite(6, LOW);
    delay(2000);
    theTime = theTime - 2;
    digitalWrite(4, LOW);
    
}
