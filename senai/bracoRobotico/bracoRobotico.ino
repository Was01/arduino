#include <Servo.h>

#define sry A3
#define srx A2
#define vrx A1
#define vry A0

Servo s1;
Servo s2;
Servo s3;
Servo s4;

int leitura1=90;
int leitura2=90;
int leitura3=90;
int leitura4=90;


void setup() {
  Serial.begin(9600);
  pinMode(vrx,INPUT);
  pinMode(vry,INPUT);
  pinMode(srx,INPUT);
  pinMode(sry,INPUT);

   s1.attach(7);
   s1.write(leitura1);
   s2.attach(6);
   s2.write(leitura2);
   s3.attach(5);
   s3.write(leitura3);
   s4.attach(4);
   s4.write(leitura4);


}

void loop() {
  leitura1=map(analogRead(vrx),0,1023,0,180);
  leitura2=map(analogRead(vry),0,1023,0,180);
  leitura3=map(analogRead(srx),0,1023,0,180);
  leitura4=map(analogRead(sry),0,1023,0,180);
  
   s1.attach(6);
   s1.write(leitura1);
   s2.attach(7);
   s2.write(leitura2);
   s3.attach(5);
   s3.write(leitura3); 
   s4.attach(4);
   s4.write(leitura4);
  

} 
