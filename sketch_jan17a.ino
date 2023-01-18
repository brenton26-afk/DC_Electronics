

void setup() {
  // put your setup code here, to run once:
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(8, HIGH);
digitalWrite(12, HIGH);
delay(1000);
digitalWrite(8, LOW);
digitalWrite(12, LOW);

delay(3000);
for(int i = 8; i <= 12; i += 2){    //i = i + 2
  digitalWrite(i, HIGH);
  delay(250);
  digitalWrite(i, LOW);
}
for(int j = 12; j >= 8; j--){
  digitalWrite(j, HIGH);
  delay(250);
  digitalWrite(j, LOW);
}
delay(1000);
//hello
}
