#include <Servo.h>


#define n_pontos 8

int pinoPot1=A5;
int pinoPot2=A3;



float amostra1[n_pontos];
float amostra2[n_pontos];

int media_movel(int pino,float *amostra);

void zera_amostra(float *amostra);

Servo s1;
Servo s2;

int leitura1=0;
int leitura2=0;


void setup(){
 
  Serial.begin(9600);
   pinMode(pinoPot1,INPUT);
   pinMode(pinoPot2,INPUT);
 
  
   s1.attach(3);
   s1.write(leitura1);
   s2.attach(4);
   s2.write(leitura2);

   zera_amostra(amostra1);
   zera_amostra(amostra2);

  
}

void loop()
{
  leitura1=map(media_movel(pinoPot1,amostra1),0,1023,0,180);
  leitura2=map(media_movel(pinoPot2,amostra2),0,1023,0,180);
  
 
  s1.write(leitura1);
  s2.write(leitura2);

  Serial.println(media_movel(pinoPot2,amostra2));
  delay(50);
}

int media_movel(int pino, float *amostra){
  for(int i=n_pontos-1;i>0;i--){
    amostra[i]=amostra[i-1];
   }
   amostra[0]=analogRead(pino);
   
   float soma=0.0;

   for(int i=0;i<n_pontos;i++){
     soma+=amostra[i];
   }
   return soma/n_pontos;
}

 

 
void zera_amostra(float *amostra){
   for(int i=0;i<n_pontos;i++){
    amostra[i]=0;
   }
  
}
