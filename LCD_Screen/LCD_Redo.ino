#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

byte customChar[] = {
  B00000,
  B11011,
  B11011,
  B00000,
  B10001,
  B01110,
  B01110,
  B00100
};

int i = 0;

void setup() {
  lcd.begin(16, 2);
  
}

void loop() {

  //for(int i = 0; i < 16; i++){}
    
    lcd.setCursor(1, 0);
    lcd.print("Hello World!");
    //lcd.setCursor(8, 1);
    //lcd.print("Hello Again!");
    
    lcd.createChar(0, customChar);
    //what does lcd.home do?
    // is it necessary to print the characters or other things
    
    //lcd.home();
    delay(500);
    
    //lcd.write(byte(0));
    delay(500);
    
    //to move the characters around:
    lcd.setCursor(i, 1);
    lcd.write(8);
    //i = i + 1;
    delay(500);
    //lcd.clear();
    if(i >= 16){
      i = 0;
    }
    
    // find out what lcd clear does to the display.
    //---> figure out how to clear the screen of all the text
    //lcd.clear();
    //how to move the img
  
  }
