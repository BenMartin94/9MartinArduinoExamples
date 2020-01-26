#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int homeS = 0;
int awayS = 0;
int input = 8;
int lightSrc = 1;
int input2 = A1;
int inputA = A0;
boolean chanRec = false;
int counter = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(input, INPUT);
  pinMode(input2, INPUT);
  pinMode(inputA, INPUT);
  pinMode(lightSrc, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Home: ");
  lcd.setCursor(10, 0);
  lcd.print("Away: ");
}
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

void loop() {
  
  // put your main code here, to run repeatedly:
  if(counter>=40){
    chanRec=false;
    counter=0;
  }
  
  //Serial.println(digitalRead(input));
  
  if(analogRead(input2)<=850&&!chanRec){
    chanRec = true;
    homeScore();
  }
  
  
  if(analogRead(inputA)<=850&&!chanRec){
    chanRec = true;
    awayScore();
  }
  updateScore();
  counter++;
  delay(50);
}
void updateScore(){
  //Serial.println(homeS);
  lcd.setCursor(0,1);
  lcd.print(homeS);
  lcd.setCursor(10,1);
  lcd.print(awayS);
}
void homeScore(){
  flash();
  chanRec = true;
  homeS++;
  
}
void awayScore(){
  flash();
  chanRec=true;
  awayS++;
  
}
void flash(){
  for(int i = 0; i< 20; i++){
    if(i%2==0){
      digitalWrite(lightSrc, HIGH);
    }
    else
      digitalWrite(lightSrc, LOW);

    delay(25);
  }

}

