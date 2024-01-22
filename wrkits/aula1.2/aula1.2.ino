


int leitura=0;

void setup() {
 pinMode(3,OUTPUT);
 pinMode(A0,INPUT);

}

void loop() {
  leitura=analogRead(A0);
  if(leitura>512){
    digitalWrite(3,HIGH);
  }
  else{
    digitalWrite(3,LOW);
  }

}
