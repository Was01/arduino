// C++ code
//


int leitura;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  leitura=analogRead(A0);
  Serial.println(leitura);
}
