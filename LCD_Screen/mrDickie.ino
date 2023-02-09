#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte miniDickie[] = {
  B00000,
  B11111,
  B00010,
  B01000,
  B01000,
  B00000,
  B00100,
  B10101
};

void setup(){
  lcd.begin(16, 2)
  //could make 2,2 just for one image
}

void loop(){
  //3 by 2
  lcd.setCursor(0,0);
}
