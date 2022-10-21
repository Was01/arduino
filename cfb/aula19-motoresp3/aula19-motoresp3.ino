# define motor 3
# define pot A0
int leitura=0;
void setup()
{
  pinMode(motor, OUTPUT);
  pinMode(pot,INPUT);
}

void loop()
{
  leitura=map(analogRead(pot),0,1023,0,255);
  analogWrite(motor,leitura);

}
