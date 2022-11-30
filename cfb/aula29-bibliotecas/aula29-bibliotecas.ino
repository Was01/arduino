#include "CFB_ultrassonico.h"









const byte triggerPin = 5;
const byte echoPin = 4;
CFB_ultrassonico CFB_ultrassonico(triggerPin, echoPin);

void setup () {
    Serial.begin(9600); 
}

void loop () {
  
    //A cada 500 milisegundos, faz-se uma medida usando o sensor e mostra na tela a distância em centímetros.
    float distancia= CFB_ultrassonico.distancia_cm();
    Serial.println(distancia);
    delay(500);
}
