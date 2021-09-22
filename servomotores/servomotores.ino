#include<Servo.h>

#define pot A0

Servo s1;
int angs1;


void setup()
{
  s1.attach(3);
  angs1=0;
  s1.write(angs1);
  pinMode(pot,INPUT);
}

void loop()
{
   angs1=map(analogRead(pot),0,1023,0,180);
    s1.write(angs1);
    delay(100);
}
