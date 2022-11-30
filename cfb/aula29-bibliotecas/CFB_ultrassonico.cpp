#include "CFB_ultrassonico.h"

CFB_ultrassonico::CFB_ultrassonico(int pt,int pe){
	this->pino_trigger=pt;
	this->pino_echo=pe;
	pinMode(pino_trigger,OUTPUT);
	pinMode(pino_echo,INPUT);
}

double CFB_ultrassonico::distancia_cm(){
	digitalWrite(pino_trigger,LOW);
	delayMicroseconds(2);
	digitalWrite(pino_trigger,HIGH);
	delayMicroseconds(10);
    digitalWrite(pino_trigger,LOW);
    unsigned long microsegundos=pulseIn(pino_echo,HIGH);
	double distancia=(microsegundos*0.0343)/2.0;
	if(distancia==0|| distancia>400){
		return -1.0;
	}else{
		return distancia;
	}
}
