#include <UltrasonicHCSR04.h>

#include<Servo.h>

#define pinoServo 7

Servo s;

// Define os pinos para o Trigger e Echo
const int pinoTrigger = 8;
const int pinoEcho = 9;


// Inicializa o sensor (Trigger, Echo)
UltrasonicHCSR04 ultrasonic(pinoTrigger, pinoEcho);


void setup() {
  Serial.begin(9600);
  s.attach(pinoServo);
  s.write(0); // Começa na posição 0
  
  Serial.println("Sistema Iniciado...");
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
    s.write(80);
  } 
  else {
    s.write(0);
  }

  delay(300); // Delay de 200ms para estabilidade

}
