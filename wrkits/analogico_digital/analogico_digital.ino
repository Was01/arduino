#define pot1 A0


void setup() {
  pinMode(pot1,INPUT);

  Serial.begin(9600);
}

void loop() {
  float leitura=analogRead(pot1);
  float tensao=(5*leitura)/1023;
  Serial.println(tensao);
  
  Serial.println("");
  delay(500);

}
