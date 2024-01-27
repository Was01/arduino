# include<Servo.h>
# define pot1 A0
# define pot2 A1
# define pot3 A2

Servo s1;
Servo s2;
Servo s3;
int angS1;
int angS2;
int angS3;

void setup()
{
  angS1=0;
  angS2=0;
  angS3=0;
  s1.attach(3);
  s2.attach(4);
  s3.attach(5);
  s1.write(angS1);
  s2.write(angS2);
  s3.write(angS3);

}

void loop(){
  angS1=map(analogRead(pot1),0,1023,0,180);
  angS2=map(analogRead(pot2),0,1023,0,180);
  angS3=map(analogRead(pot3),0,1023,0,180);
  s1.write(angS1);
  s2.write(angS2);
   s3.write(angS3);
   delay(100);
  
  
}
