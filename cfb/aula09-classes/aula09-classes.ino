class Btn{
  public:
  int  botao_clicado, botao_liberado,pino;  
    Btn(int p){
      pino=p;
      botao_clicado=0;
      botao_liberado=0;
  }
    bool Press(){
      if(digitalRead(pino)==HIGH){
        botao_clicado=1;
        botao_liberado=0;
      }else{
        botao_liberado=1;
      }
      if(botao_clicado==1 and botao_liberado==1){
        botao_clicado=0;
        botao_liberado=0;
        return true;
      }else
        return false;
    } 
};

class Cor{
  public:
    int led_vermelho,led_azul,led_verde,maximo,ciclo;
    Cor(int pino_vermelho,int pino_azul,int pino_verde){
      led_vermelho=pino_vermelho;
        led_azul=pino_azul;
        led_verde=pino_verde;
        ciclo=0;
        maximo=4;
    }
    void TrocaLed(){
      switch(ciclo){
        case 0:
          CorLed(1,0,0);
          break;
        case 1:
          CorLed(0,1,0);
          break;
      case 2:
          CorLed(0,0,1);
          break;  
        case 3:
          CorLed(0,0,0);
          break;
      }
      ciclo++;
      if(ciclo>maximo-1){
        ciclo=0;
      }
    }
  private:
    void CorLed(int r,int b,int g){
      digitalWrite(led_vermelho,r);
      digitalWrite(led_azul,b);
      digitalWrite(led_verde,g);
  }
};

Btn botao(7);
Cor cor(2,3,4);

void setup(){
  pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(7,INPUT);
}

void loop(){
  if(botao.Press()){
      cor.TrocaLed();
  }
}
