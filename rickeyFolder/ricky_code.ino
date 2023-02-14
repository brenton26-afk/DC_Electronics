#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte N1[8] = {
  B00100,
  B01100,
  B10100,
  B10100,
  B00100,
  B00100,
  B00100,
  B11111
  };

byte N2[8] = {
  B00110,
  B01100,
  B10100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  };

void setup() {
  lcd.begin(16,2);
  lcd.createChar(3, N1);
  lcd.createChar(2, N2);
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(2,0);
  lcd.write(byte(2));
}

void loop(){
  
  }
