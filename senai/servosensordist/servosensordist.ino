# include <HCSR04.h>
# include <Servo.h>



//Inicializa o sensor usando os pinos digitais 5 e 4.
const byte triggerPin = 5;
const byte echoPin = 4;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);


Servo s;

void setup () {
    Serial.begin(9600); 
    s.attach(3);
}


void loop () {
  
    //A cada 500 milisegundos, faz-se uma medida usando o sensor e mostra na tela a distância em centímetros.
    float distance = distanceSensor.measureDistanceCm();
    Serial.println(distance);
    if(distance<3.5){
        for(int angulo=0;angulo<=180;angulo++){
            s.write(angulo);
             delay(10);
         }
  
        for(int angulo=180;angulo>=0;angulo--){
            s.write(angulo);
            delay(10);
         }
      
     }
    delay(500);
}
