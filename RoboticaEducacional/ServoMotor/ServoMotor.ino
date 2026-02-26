// C++ code
//
#include <Servo.h>

Servo myservo;

#define pot A1

void setup()
{
  myservo.attach(7);
  pinMode(pot,INPUT);
}

void loop()
{
  int val=map(analogRead(pot),0,1023,0,180);
  myservo.write(val);
  delay(15);
}
