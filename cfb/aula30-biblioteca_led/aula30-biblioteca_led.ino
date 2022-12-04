#include "CFB_led.h"

int pinovermelho=7;
int pinoverde=6;
int pinoamarelo=5;

CFB_led ledvermelho(pinovermelho);
CFB_led ledverde(pinoverde);
CFB_led ledamarelo(pinoamarelo);

void setup() {
 
}

void loop() {
  ledvermelho.piscar(50);
  ledverde.piscar(50);
  ledamarelo.piscar(50);

}
