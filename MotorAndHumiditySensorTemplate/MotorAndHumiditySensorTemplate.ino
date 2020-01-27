#include "Servo.h"

Servo motor;

int analogInputPin;; // this is the pin for analog input
int voltageInputVal; 

int motorPin;

bool gateOpen; //true or false=(!true)

void setup() {
  // put your setup code here, to run once:
  analogInputPin = A2;//insert appropriate pin for HS
  motorPin = 3;//insert appropriate value for motor control
  motor.attach(motorPin);
  gateOpen = false;
}

void loop() {
  // put your main code here, to run repeatedly:

  voltageInputVal = analogRead(analogInputPin);

  if(voltageInputVal<20/*insert minimum threshold here in place of 20*/&&!gateOpen){
    //insert code open gate
    
    gateOpen = true;
  }
  if(voltageInputVal>1000/*insert minimum threshold here in place of 20*/&&gateOpen){
    //inser code to close gate
    
    gateOpen = false;
  }

}
