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

byte top1[] = {
  B00000,
  B00000,
  B00010,
  B00110,
  B01110,
  B11110,
  B11110,
  B11111
};

byte top2[2] = {
  B00000,
  B01110,
  B01000,
  B01001,
  B11001,
  B01101,
  B00111,
  B10001
};

byte top3[3] = {
  B00000,
  B00100,
  B01100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte bottom1[4] = {
  B11111,
  B11110,
  B11110,
  B01110,
  B00110,
  B00010,
  B00000,
  B00000
};

byte bottom2[5] = {
  B10001,
  B00111,
  B01101,
  B11001,
  B01001,
  B01000,
  B01110,
  B00000
};

byte bottom3[6] = {
  B00100,
  B00100,
  B00101,
  B00101,
  B00101,
  B01101,
  B00100,
  B00000
};

void setup(){
  lcd.begin(16, 2);
  //could make 2,2 just for one image
}

void loop(){
  //3 by 2
  lcd.setCursor(0, 0);
  lcd.createChar(1, top1);
  lcd.write(1);
  
  lcd.setCursor(1, 0);
  lcd.createChar(2, top2);
  lcd.write(1);
  
  lcd.setCursor(2, 0);
  lcd.createChar(3, top3);
  lcd.write(2);
  
  lcd.setCursor(0, 1);
  lcd.createChar(4, bottom1);
  lcd.write(8);
  
  lcd.setCursor(1, 1);
  lcd.createChar(5, bottom2);
  lcd.write(4);
  
  lcd.setCursor(2, 1);
  lcd.createChar(6, bottom3);
  lcd.write(5);

  delay(1000);
}
