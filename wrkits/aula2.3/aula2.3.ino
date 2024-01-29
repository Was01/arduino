
 #define led1 8
 #define led2 9
 #define pot A0
 #define btn 10

 unsigned long atual_ms,ultimo_ms=0,count=0,tempo_seg=0;


 unsigned long tempo_adj=1000;

 bool btn_flag=0;





void setup() {
  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(btn,INPUT_PULLUP);
  pinMode(pot,INPUT);

  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  

}

void loop() {
  tempo_adj=analogRead(pot);
  tempo_adj=map(tempo_adj,0,1023,10,100);
  atual_ms=millis();

  if(!digitalRead(btn)) btn_flag=1;

  if((atual_ms-ultimo_ms)==100)
  {
    ultimo_ms=atual_ms;
    count++;

    if(btn_flag) tempo_seg++;

    if(tempo_seg==tempo_adj)
    {
      while(1) 
      {
        digitalWrite(led2,HIGH);
        digitalWrite(led1,LOW);
      }
    }

    digitalWrite(led1,!digitalRead(led1));

    if(count==5)
    {
      count=0;
      Serial.print("Tempo ajustado: ");
      Serial.print(0.1*tempo_adj);
      Serial.println(" segundos");
    }   
  }
}
