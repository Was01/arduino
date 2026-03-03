#include <UltrasonicHCSR04.h>


#define led  13

// Define os pinos para o Trigger e Echo
const int pinoTrigger = 2;
const int pinoEcho = 3;
// Inicializa o sensor (Trigger, Echo)
UltrasonicHCSR04 ultrasonic(pinoTrigger, pinoEcho);


void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
 
}

void loop() {
  

  // Mede a distância em centímetros
  int distancia = ultrasonic.measureDistanceCM();
// Exibe no monitor para conferência
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Lógica do Servo
  if (distancia > 0 && distancia < 20) {
    digitalWrite(led,HIGH);
  } 
  else {
    digitalWrite(led,LOW);
  }

  delay(200); // Delay de 200ms para estabilidade

}
