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

byte top1[8] = {
  B00000,
  B00000,
  B00010,
  B00110,
  B01110,
  B11110,
  B11110,
  B11111
};

byte top2[8] = {
  B00001,
  B01111,
  B01001,
  B01001,
  B11001,
  B01101,
  B00111,
  B10001
};

byte top3[8] = {
  B00000,
  B00100,
  B01101,
  B00101,
  B00101,
  B00101,
  B00100,
  B00100
};

byte bottom1[8] = {
  B11111,
  B11110,
  B11110,
  B01110,
  B00110,
  B00010,
  B00000,
  B00000
};

byte bottom2[8] = {
  B10001,
  B00111,
  B01101,
  B11001,
  B01001,
  B01001,
  B01111,
  B00001
};

byte bottom3[8] = {
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
  //could make 3,2 just for one image
  lcd.createChar(1, top1);
  lcd.createChar(2, top2);
  lcd.createChar(3, top3);
  lcd.createChar(4, bottom1);
  lcd.createChar(5, bottom2);
  lcd.createChar(6, bottom3);
  
  lcd.setCursor(0, 0);
  
  lcd.home();
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.setCursor(0,1);
  lcd.write(byte(4));
  lcd.write(byte(5));
  lcd.write(byte(6));
}

void loop(){
  //delay(1000);
}
