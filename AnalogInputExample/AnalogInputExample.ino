
int analogInputPin;; // this is the pin for analog input
int voltageInputVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //This is for communication with the computer
}

void loop() {
  // put your main code here, to run repeatedly:
  voltageInputVal = analogRead(analogInputPin);//this will read the pin and give a value between 0-1023, which corresponds to a voltage between 0-5v
  Serial.println(voltageInputVal);//sends the reading to the computer to see
}
