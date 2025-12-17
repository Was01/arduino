// C++ code
//

#define pot A1
void setup()
{
  Serial.begin(9600);
  pinMode(pot, INPUT);
}

void loop()
{
  int leitura=analogRead(pot);
  Serial.println(leitura);
  delay(1000);
}
