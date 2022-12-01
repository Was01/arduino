# include "CFB_led.h"

CFB_led::CFB_led(int pin){
	this->pino_led=pin;
	pinMode(pino_led,OUTPUT);
}

void CFB_led::acender(){
	digitalWrite(pino_led,HIGH);
}

void CFB_led::apagar(){
	digitalWrite(pino_led,LOW);
	
}

void CFB_led::acender_t(int tmp){
	acender();
	delay(tmp);
	apagar();
}

void CFB_led::apagar_t(int tmp){
	apagar();
	delay(tmp);
	acender();
}

void CFB_led::piscar(int tmp){
		acender_t(tmp);
		delay(tmp);
		apagar_t(tmp);
		delay(tmp);
	
	
}