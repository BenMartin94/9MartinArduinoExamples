#include "Servo.h"

Servo myServo;

int inputPin;

int STOPSPEED = 87;//constant for soeed
int MOVESPEED = 91;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);//9 is the pin for servo signal
  Serial.begin(9600);
  inputPin = 6;
  pinMode(inputPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int inputVal=digitalRead(inputPin); // gets the voltage on the input pin
  Serial.println(inputVal);
  if(inputVal==1){ // checks the value if high turn the motor
    myServo.write(MOVESPEED);
    delay(2000);//stop processor for 2s
    myServo.write(STOPSPEED);
  }
  else{
    myServo.write(STOPSPEED);
  }//dont mind me
  
  
}
