#include <LiquidCrystal.h>

//black wire green led: 12
//blue leds: 11, 10
//whites: 9,8
//orange: 7
//green --> yellows: 5-2

LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

int randomNum;
double pauseTime;
double startTime;

int lightSwitch;
int led;

int buttonState = 0;
bool buttonPressed = false;
bool gameStart = false;

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.home();
  lcd.print("Hello World");
  delay(1000);
  lcd.clear();
  Serial.println("Start!");

  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop(){
  runGame();
  Serial.print("Time: ");
  Serial.println(pauseTime);
}

void runGame(){
  if(gameStart == false){
    
    
    lcd.setCursor(0, 0);
    lcd.print("Get ready...");
    
    
    randomNum = random(2000, 10000);

    for(int i = 0; i < randomNum; i++){
      delay(1);
      buttonState = digitalRead(7);
    }
    //delay(randomNum);
    if(buttonState == HIGH){
        gameStart = false;
        buttonPressed = true;
      }else{
    
    lcd.clear();
    startTime = millis();

    lcd.setCursor(6, 0);
    lcd.print("Go!");
    gameStart = true;
      }
  }
  
  
  
  if(gameStart == true){
    
    buttonState = digitalRead(7);
    buttonPressed = false;
    //button
    if(buttonState == HIGH && buttonPressed == false){
      
      pauseTime = millis() - startTime;
      pauseTime = pauseTime / 1000;
      
      Serial.println(pauseTime);
      lcd.setCursor(0, 1);
      lcd.write("Pressed: ");
      lcd.print(pauseTime);
      
      buttonPressed = true;
      delay(1000);
      
      //turn on lights
      if(pauseTime <= 0.19){
        led = 12;
      }else if(pauseTime > 0.19 && pauseTime <= 0.4){
        led = 11;
      } else if(pauseTime > 0.4){
        led = 10;
      }
      
      lightSwitch = 1;
      light(lightSwitch, led);
      //digitalWrite(12, HIGH);
      
      delay(1000);
      gameStart = false;
    }
  }

  if(gameStart == false){
    lightSwitch = 0;
    light(lightSwitch, led);
    lcd.home();
    lcd.write("Game Over");
    delay(3000);
    pauseTime = 0.00;
    //Serial.println("All done.");
    lcd.clear();
  }
}


void light(int li, int pin){
  digitalWrite(pin, li);
}
