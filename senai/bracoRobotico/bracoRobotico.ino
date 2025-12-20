#include <Servo.h>

// Definição dos pinos para facilitar a leitura
#define PIN_SRY A3
#define PIN_SRX A2
#define PIN_VRX A1
#define PIN_VRY A0

Servo s1, s2, s3, s4;

void setup() {
  Serial.begin(9600);

  // Atribuição dos pinos (Apenas uma vez no setup)
  s1.attach(7);
  s2.attach(6);
  s3.attach(5);
  s4.attach(4);

  // Posição inicial centralizada
  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);
}

void loop() {
  // Leitura e mapeamento direto
  // Mapeamos de 0-1023 (analog) para 0-180 (graus do servo)
  int pos1 = map(analogRead(PIN_VRX), 0, 1023, 0, 180);
  int pos2 = map(analogRead(PIN_VRY), 0, 1023, 0, 180);
  int pos3 = map(analogRead(PIN_SRX), 0, 1023, 0, 180);
  int pos4 = map(analogRead(PIN_SRY), 0, 1023, 0, 180);

  // Envia o comando para os servos
  s1.write(pos1);
  s2.write(pos2);
  s3.write(pos3);
  s4.write(pos4);

  // Pequeno delay para estabilidade mecânica e reduzir ruído
  delay(15); 
}
