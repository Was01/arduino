#include <Servo.h>

#define vrx A1
#define vry A0

Servo s1;
Servo s2;

int leitura1=90;
int leitura2=90;


void setup() {
  Serial.begin(9600);
  pinMode(vrx,INPUT);
  pinMode(vry,INPUT);

   s1.attach(7);
   s1.write(leitura1);
   s2.attach(6);
   s2.write(leitura2);

}

void loop() {
  leitura1=map(analogRead(vrx),0,1023,0,180);
  leitura2=map(analogRead(vry),0,1023,0,180);
   s1.attach(6);
   s1.write(leitura1);
   s2.attach(7);
   s2.write(leitura2);
  

} 
