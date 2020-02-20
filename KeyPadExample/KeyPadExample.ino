#include "Servo.h"
Servo servo;


int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;
int pin5 =6;
int pin6 = 7;
int pin7 = 8;
int pin8 = 9;
void setup() {
  // put your setup code here, to run once:
  servo.attach(10);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int col = pollCol();
  int row = pollRow();
  if (col==1&&row==1){
    servo.write(20);
    delay(1000);
  }
  else if (col==2&&row==1){
    servo.write(10);
    delay(500);
  }
  else if (col==3&&row==1){
    servo.write(5);
    delay(100);
  }
  
  
  else{
    servo.write(90);
  }
  String toPrint = String(row) + " " + String(col);
  Serial.println(toPrint);
}

int pollRow(){
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, INPUT);
  pinMode(pin8, INPUT);
  
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, HIGH);
  if(digitalRead(pin5)>0){
    return 4;
  }
  
  
  if(digitalRead(pin6)>0){
    return 3;
  }
  
  
  if(digitalRead(pin7)>0){
    return 2;
  }
  
  
  if(digitalRead(pin8)>0){
    return 1;
  }
  digitalWrite(pin4, LOW);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, LOW);
  digitalWrite(pin1, LOW);
  return -1;
}

int pollCol(){
  pinMode(pin1, INPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  digitalWrite(pin6, HIGH);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin8, HIGH);
  if(digitalRead(pin1)>0){
    return 4;
  }
  
  
  if(digitalRead(pin2)>0){
    return 3;
  }
  
  
  if(digitalRead(pin3)>0){
    return 2;
  }
  
  
  if(digitalRead(pin4)>0){
    return 1;
  }
  digitalWrite(pin5, LOW);
  digitalWrite(pin6, LOW);
  digitalWrite(pin8, LOW);
  digitalWrite(pin7, LOW);
  return -1;
  
}

