# include<Servo.h>
# define pot1 A0
# define pot2 A1

Servo s1;
Servo s2;
int angS1;
int angS2;


void setup()
{
  angS1=0;
  angS2=0;
  s1.attach(3);
  s2.attach(4);
  s1.write(angS1);
  s2.write(angS2);

}

void loop(){
  angS1=map(analogRead(pot1),0,1023,0,180);
  angS2=map(analogRead(pot2),0,1023,0,180);
  s1.write(angS1);
  s2.write(angS2);
   delay(100);
  
  
}
