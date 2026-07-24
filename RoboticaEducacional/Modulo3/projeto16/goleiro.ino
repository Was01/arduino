#include <Servo.h>

#define potx A1


Servo s1 ; // Removemos os que não estão sendo usados

void setup() {
  Serial.begin(9600);
  pinMode(potx, INPUT);
  

  s1.attach(8);
  s1.write(90);

}

void loop() {
  int pos1 = map(analogRead(potx), 0, 1023, 0, 180);
  Serial.println(pos1);
  s1.write(pos1);
  


  delay(50); // Evita trepidações e economiza processamento
}