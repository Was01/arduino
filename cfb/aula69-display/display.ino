
#define tmp 1000
int disp_pinos[7] = {2, 3, 4, 5, 6, 7, 8};
int cont=5;


int digitos[6][7] = {
  // a, b, c, d, e, f, g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}  // 5
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(disp_pinos[i], OUTPUT);
  }
}


void loop() {
  digito(cont);
  delay(tmp);
  cont--;
  if (cont<0) cont=5;
  
}

void digito (int d){
  for(int i=0;i<7;i++){
    digitalWrite(disp_pinos[i],digitos[d][i]);
  }
}