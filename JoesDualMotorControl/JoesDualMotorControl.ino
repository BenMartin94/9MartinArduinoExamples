#include <Servo.h>


#define cW 10
#define noRot 90
#define cCW 170

Servo servo;
Servo servo1;


void setup() {
  // put your setup code here, to run once:
  servo.attach(9);
  servo1.attach(8);
}

void loop() {
  turnRight(2000);
  stp(2000);
  turnLeft(2000);
  forward(2000);
  stp(2000);
  backwards(2000);
  // put your main code here, to run repeatedly:
  
}

void turnRight(int duration){
  servo.write(cW);
  servo1.write(noRot);
  delay(duration);
}

void turnLeft(int duration){
  servo1.write(cW);
  servo.write(noRot);
  delay(duration);
}
void stp(int duration){
  servo.write(noRot);
  servo1.write(noRot);
  delay(duration);
}
void forward(int duration){
  servo.write(cW);
  servo1.write(cW);
  delay(duration);
}
void backwards(int duration){
  servo.write(cCW);
  servo1.write(cCW);
  delay(duration);
}

