
#define led1 8
#define led2 9




void Blink_ms(unsigned ms1,unsigned ms2,const int pino1,const int pino2);
   

void setup() {

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);

}

void loop() 
{
 Blink_ms(100,200,led1,led2);
}

void Blink_ms(unsigned ms1,unsigned ms2,const int pino1,const int pino2)
{
  static unsigned long atual_ms1,atual_ms2,ultimo_ms1=0,ultimo_ms2=0;
  atual_ms1=millis();
  atual_ms2=millis();

  if((atual_ms1-ultimo_ms1)==ms1)
  {
    ultimo_ms1=atual_ms1;
    digitalWrite(pino1,!digitalRead(pino1));
  }

  if((atual_ms2-ultimo_ms2)==ms2)
  {
    ultimo_ms2=atual_ms2;
    digitalWrite(pino2,!digitalRead(pino2));
  }


}