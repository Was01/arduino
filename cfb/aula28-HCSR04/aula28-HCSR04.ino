#include <HCSR04.h>


//Inicializa o sensor usando os pinos digitais 5 e 4.
const byte triggerPin = 5;
const byte echoPin = 4;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
    Serial.begin(9600); 
}

void loop () {
  
    //A cada 500 milisegundos, faz-se uma medida usando o sensor e mostra na tela a distância em centímetros.
    float distance = distanceSensor.measureDistanceCm();
    Serial.println(distance);
    delay(500);
}
