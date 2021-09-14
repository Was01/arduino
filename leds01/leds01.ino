
#define led_verde 13
#define led_amarelo 12
#define led_vermelho 11



void setup()
{
  pinMode(led_verde, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
}

void verde( int tmp){
  digitalWrite(led_verde, HIGH);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, LOW);
  delay(tmp*1000); 
}

void amarelo( int tmp){
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarelo, HIGH);
  digitalWrite(led_vermelho, LOW);
  delay(tmp*1000); 
}

void vermelho( int tmp){
  digitalWrite(led_verde, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_vermelho, HIGH);
  delay(tmp*1000); 
}
void loop(){
  vermelho(7);
  amarelo(2);
  verde(9);
  
}
