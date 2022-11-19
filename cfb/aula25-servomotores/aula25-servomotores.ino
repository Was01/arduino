# include <Servo.h>
#define pot A0
int leitura;
Servo s1;

void setup()
{
  s1.attach(3);
  leitura=0;
  s1.write(leitura);
  
}

void loop()
{
  leitura=map(analogRead(pot),0,1023,0,180);
  s1.write(leitura);
  delay(100);
}
