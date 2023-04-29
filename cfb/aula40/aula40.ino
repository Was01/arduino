#include "notas.h"

#define som 9

//Tempos das notas
#define t4 2000 //4 tempos
#define t2 1000 //2 tempos
#define t1 500  //1 tempo
#define t05 250 //1/2 tempo
#define t025 125//1/4 tempo

#define pausa 125

double ritmo=1;

int musica[]={
  NOTA_C4,NOTA_C4,
  NOTA_D4,NOTA_C4,NOTA_F4,
  NOTA_E4,NOTA_C4,NOTA_C4,
  NOTA_D4,NOTA_C4,NOTA_G4,
  NOTA_F4,NOTA_C4,NOTA_F4,
  NOTA_C5,NOTA_A4,NOTA_F4,
  NOTA_E4,NOTA_D4,NOTA_AS4,NOTA_AS4,
  NOTA_A4,NOTA_F4,NOTA_G4,
  NOTA_F4 
};

int duracoes[]={
  t05,t05,
  t1,t1,t1,
  t2,t05,t05,
  t1,t1,t1,
  t2,t05,t05,
  t1,t1,t1,
  t1,t1,t05,t05,
  t1,t1,t1,
  t2
};

void setup() {
  pinMode(som,OUTPUT);

}

void loop() {
  for(int nota=0;nota<(sizeof(musica)/sizeof(int));nota++){
    int duracaoNota=duracoes[nota]/ritmo;
    tone(som,musica[nota],duracaoNota);
    delay(duracaoNota*1.3);
    noTone(som);
  }
  delay(5000);
}
