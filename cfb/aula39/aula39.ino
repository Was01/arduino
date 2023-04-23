#define som 9


void setup() {
  pinMode(som,OUTPUT);
}

void loop() {
  // tone(porta,freq);
  //31-4978;
  tone(som,200,500);
  delay(550);
  tone(som,300,500);
  delay(550);
  tone(som,400,500);
  delay(550);
  tone(som,500,500);
  delay(550);
  tone(som,200,500);
  delay(550);
  tone(som,600,500);
  delay(3000);
}
