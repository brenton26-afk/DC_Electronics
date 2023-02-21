#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int randomNum;
long pauseTime;
long startTime;

int buttonState = 0;

bool buttonPressed = false;

void setup(){
  lcd.begin(16, 2);
  lcd.home();
  lcd.print("Hello World");
  delay(1000);
  lcd.clear();
  
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Get ready...");
  randomNum = random(2000, 10000);
  delay(randomNum);
  lcd.clear();
  lcd.setCursor(6, 0);
  lcd.print("Go!");
  startTime = millis();
  buttonState = digitalRead(7);
  if(buttonState == HIGH){
    pauseTime = millis() - startTime;
  }
  
  delay(3000);
  lcd.clear();
}
