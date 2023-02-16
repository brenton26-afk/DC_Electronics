// starter code for an interesting push button

int pin1 = 10;
int buttonPin = 0;
int buttonState = 0;

void setup(){
  Serial.begin(9600);
  Serial.println("Hello World!");
  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, HIGH);
  //Ricky code start:
   
  //Riky code end.
}

void loop(){
  //Ricky code start:
    buttonState = digitalRead(buttonPin);

   if(buttonState == HIGH){
    digitalWrite(pin1, HIGH);
    }
    
   if(buttonState == LOW){
    digitalWrite(pin1, LOW);
    }

    
  //Ricky code end.
  }
