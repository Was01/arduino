
#define btn 8
#define led 9
#define led2 10

bool flag=0;
int leitura;

void setup() {
  Serial.begin(9600);
  pinMode(btn,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  
 digitalWrite(led,LOW);
 digitalWrite(led2,HIGH);

}

void loop() 
{
  if(!digitalRead(btn)) flag=1;

  if(digitalRead(btn)&& flag){
    flag=0;
    digitalWrite(led,!digitalRead(led));
    digitalWrite(led2,!digitalRead(led2));

  }
  leitura=digitalRead(btn);
  Serial.println(leitura);
  delay(130);
}
