// C++ code
//
#define led 4
#define btn 3
int botao_clicado=0;
int botao_liberado=0;

void trocaLed(){ 
  if(digitalRead(led)==HIGH){
    digitalWrite(led,LOW);
  }else{
    digitalWrite(led,HIGH);
  }
}

void Analisa_botao(){
  if((botao_clicado==1)and(botao_liberado==1)){
    botao_clicado=0;
    botao_liberado=0;
    trocaLed();
  }
}

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(btn,INPUT);
}

void loop(){
  if(digitalRead(btn)==HIGH){
    botao_clicado=1;
    botao_liberado=0;
  }
  else{
      botao_liberado=1;
  }
  Analisa_botao();
}
