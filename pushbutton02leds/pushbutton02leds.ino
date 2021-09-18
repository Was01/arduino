#define led1 4
#define led2 2
#define btn 3

int btn_clicado=0;
int btn_liberado=0;

void troca_led(){
  if (digitalRead(led1)==HIGH){
   digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }
  else{
    digitalWrite(led1,HIGH);  
    digitalWrite(led2,LOW);
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
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
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
