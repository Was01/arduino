
#define led 4
#define btn 3

int btn_clicado=0;
int btn_liberado=0;

void troca_led(){
    if (digitalRead(led)==HIGH){
        digitalWrite(led,LOW);
      }else{
          digitalWrite(led,HIGH);
      } 
 }

void keyup(){
 if((btn_clicado==1) and (btn_liberado==1)){
    btn_clicado=0;
    btn_liberado=0;
    troca_led();
  } 
 }

 
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
}

void loop()
{
  if(digitalRead(btn)==HIGH){
    btn_clicado=1;
    btn_liberado=0;
  }
  else
    btn_liberado=1;
  keyup();
}
