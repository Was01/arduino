int pled=7;


class Led{
  public:
    int pino_led;
    Led(int p){
      pino_led =p;
    }
    void Liga_led(int tmp){
      Estado_led(1);
      delay(tmp); 
      Estado_led(0);
      delay(tmp);
    }
  private:
    void Estado_led(int bin){
      digitalWrite(pino_led,bin);
  }
};
    
    
Led led1(pled);
        
    
void setup()
{
  pinMode(pled,OUTPUT);
}

void loop()
{
  led1.Liga_led(1000);

}
