#define tmp 1000

#define led_verde 2
#define led_amarelo 3
#define led_vermelho 4

int disp_pinos[7] = {6, 7, 8, 9, 10, 11, 12};
int cont = 9;

// Ajustado de [6][7] para [10][7] para comportar todos os números
int digitos[10][7] = {
  // a, b, c, d, e, f, g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(disp_pinos[i], OUTPUT);
  }
  pinMode(led_verde,OUTPUT);
  pinMode(led_amarelo,OUTPUT);
  pinMode(led_vermelho,OUTPUT);
  
}

void loop() {

  digitalWrite(led_verde,HIGH);
  digitalWrite(led_amarelo,LOW);
  digitalWrite(led_vermelho,LOW);
  
  // --- PRIMEIRA SEQUÊNCIA: 9 até 0 ---
  
  for (int i = 9; i >= 0; i--) {
    digito(i);
    delay(tmp);
  }

  digitalWrite(led_verde,LOW);
  digitalWrite(led_amarelo,HIGH);
  digitalWrite(led_vermelho,LOW);

  // --- SEGUNDA SEQUÊNCIA: 2 até 0 ---
  
  for (int i = 4; i >= 0; i--) {
    digito(i);
    delay(tmp);
  }

  digitalWrite(led_verde,LOW);
  digitalWrite(led_amarelo,LOW);
  digitalWrite(led_vermelho,HIGH);

   // --- TERCEIRA SEQUÊNCIA: 9 até 0 ---
  
  for (int i = 9; i >= 0; i--) {
    digito(i);
    delay(tmp);
  }

  
  // O loop() reinicia aqui, voltando para a contagem de 9
}

void digito(int d) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(disp_pinos[i], digitos[d][i]);
  }
}
