#include <Servo.h>
#define btn1 7
#define btn2 8
#define btn3 9
#define btn4 10

Servo s1;
Servo s2;
float angulo1 = 90;
float angulo2 = 90;


void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
  s1.attach(3);
  s2.attach(4);
  s1.write(angulo1);
  s2.write(angulo2);
}


void loop() {
  if (!digitalRead(btn1) and angulo1 < 180) {
    angulo1 += 0.8;
    s1.write(angulo1);
    Serial.println(angulo1);
    delay(10);
  }

  if (!digitalRead(btn2) and angulo1 > 0) {
    angulo1 -= 0.8;
    s1.write(angulo1);
    Serial.println(angulo1);
    delay(10);
  }

   if (!digitalRead(btn3) and angulo2 < 180) {
    angulo2 += 0.8;
    s2.write(angulo2);
    Serial.println(angulo2);
    delay(10);
  }

  if (!digitalRead(btn4) and angulo2 > 0) {
    angulo2 -= 0.8;
    s2.write(angulo2);
    Serial.println(angulo2);
    delay(10);
  }
}
