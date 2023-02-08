#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7

byte customChar[] = {
  B00000,
  B11111,
  B00010,
  B01000,
  B01000,
  B00000,
  B00100,
  B10101
};

int i = 5;

void setup() {
  lcd.begin(16, 2);
  
}

void loop() {

  //for(int i = 0; i < 16; i++){}
    lcd.setCursor(0, 5);
    lcd.createChar(7, customChar);
    lcd.home();
    lcd.write(8);
    delay(500);
    i = i + 1;
    if(i >= 16){
      i = 0;
    }
    lcd.clear();
    //how to move the img
  
  }
