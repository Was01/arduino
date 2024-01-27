# define btn 7
# define led_verde 4
# define led_azul 3
# define led_vermelho 2
# define maximo 4

int botao_clicado = 0;
int botao_liberado = 0;
int ciclo = 0;

void vermelho() {
  digitalWrite(led_vermelho, HIGH);
  digitalWrite(led_azul, LOW);
  digitalWrite(led_verde, LOW);
}

void verde() {
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_azul, LOW);
  digitalWrite(led_verde, HIGH);
}

void azul() {
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_azul, HIGH);
  digitalWrite(led_verde, LOW);
}

void desliga(){
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_azul, LOW);
  digitalWrite(led_verde, LOW);
}
  
  



void trocaLed() {
  switch (ciclo) {
    case 0:
      vermelho();
      break;
    case 1:
      verde();
      break;
    case 2:
     azul();
      break;
    case 3:
      desliga();
      break;
  }
  ciclo++;
  if (ciclo > maximo - 1)
    ciclo = 0;
}

void verifica_btn() {
  if (botao_clicado == 1 and botao_liberado == 1) {
    botao_clicado = 0;
    botao_liberado = 0;
    trocaLed();
  }
}


void setup()
{
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(btn, INPUT);
}

void loop()
{
  if (digitalRead(btn) == HIGH) {
    botao_clicado = 1;
    botao_liberado = 0;
  } else
    botao_liberado = 1;
  verifica_btn();

}
