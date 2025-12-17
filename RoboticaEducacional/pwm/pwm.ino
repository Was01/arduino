// C++ code
//

#define pot A1
# define led 3
void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(led,OUTPUT);
}

void loop()
{
  int leitura=map(analogRead(pot),0,1023,0,255);
  Serial.println(leitura);
  analogWrite(led,leitura);
  delay(1000);
}
