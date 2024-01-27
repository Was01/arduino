
#define out1 8
#define out2 9



class LED
{
  public:
     int pino;
     LED(int pin)
    {
          pino=pin;
    }

    void Blink_Ms(unsigned ms)
    {
      static unsigned long ultimo_ms=0;
      if((millis()-ultimo_ms)==ms)
      {
        ultimo_ms=millis();
        digitalWrite(pino,!digitalRead(pino));
      }
    }
};

void setup() {

  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  digitalWrite(8,LOW);
  digitalWrite(9,LOW);

}

void loop() 
{
 LED led1(8),led2(9);
 led1.Blink_Ms(100);
 led2.Blink_Ms(200);

}
