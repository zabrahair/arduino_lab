// this demo refer to file: Arduino_Starter_Kit_Manual-Mar2010.pdf

// Analog in 0 connected to the potentiometer
int potPin = 0;
// connected to the base of the ransistor
int transistorPin = 11;
// value returned from the potentiometer
int potValue = 0;

void setup(){
  // set the transistor poin as outpout
  pinMode( transistorPin, OUTPUT);
}

void loop(){
  // read the potentiometer, convert it to 0 -255:
  potValue = analogRead(potPin) / 4;
  // use that to control the transistor:
  analogWrite(transistorPin, potValue);
}

