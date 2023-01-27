int button = 0;
int score = 0;


long startTime;

bool pressed = false;
bool game = false;

bool seven = true;
bool six = true;
bool four = true;

void setup(){
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
  Serial.println("Hello World");
}

void loop(){
  button = digitalRead(2);
  
  if(pressed == false && button == HIGH){
    score++;
    pressed = true;
    Serial.println(score);
      
      if(score == 1){
        startTime = millis();
        game = true;
        Serial.println(startTime);
        }
  
  } else if(button == LOW){
    pressed = false;
  }

	if(seven == true)
		{digitalWrite(7, HIGH);}
  if(six == true)
		{digitalWrite(6, HIGH);}
	if(four == true)
		{digitalWrite(4, HIGH);}

    
   if(millis() - startTime >= 3000 && game == true){
     digitalWrite(7, LOW);
		 seven = false;
   }

   if(millis() - startTime >= 4000 && game == true){
     digitalWrite(6, LOW);
		 six = false;
   }

   if(millis() - startTime >= 5000 && game == true){
     digitalWrite(4,LOW);
		 four = false;
   }

	//turn on game lights as the score goes up
   if(score >= 5){
  	 digitalWrite(8, HIGH);
  }
  
	 if(score >= 10){
  	 digitalWrite(9, HIGH);
  }
  
	 if(score >= 15){
  	 digitalWrite(10, HIGH);
  }
  
	 if(score >= 20){
  	 digitalWrite(11, HIGH);
  }
  
	 if(score >= 25){
  	 digitalWrite(12, HIGH);
  }



}
