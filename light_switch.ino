  char blueToothVal;       //value sent over via bluetooth
  char lastValue;          //stores last state of device (on/off)
  
  // setup servo library and the start position
  # include <Servo.h> // include servo library
  Servo servoSpeaker; // declare switch servo

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  servoSpeaker.attach(9); // attach servo to pin 9
}

void loop() { 
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {//if there is data being recieved
    blueToothVal = Serial.read(); //read it
  }
  if (blueToothVal == 'u')
  {//if value from bluetooth serial is n
    servoSpeaker.write(0);   // turn servo upwards
    if (lastValue != 'u')
    lastValue = blueToothVal;
  }
  else if (blueToothVal == 'd')
  {//if value from bluetooth serial is n
    servoSpeaker.write(180);   // turn servo downwards
    if (lastValue != 'd')
    lastValue = blueToothVal;
  }
  delay(1000);
}
