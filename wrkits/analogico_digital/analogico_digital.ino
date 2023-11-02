#define pot1 A0
#define out1 7

void setup() {
  pinMode(pot1,INPUT);
  pinMode(out1,OUTPUT);
  digitalWrite(out1,LOW);

  Serial.begin(9600);
}

void loop() {
  float leitura=analogRead(pot1);
  float tensao=(5*leitura)/1023.0;
  Serial.println(tensao);
   Serial.println("");
  if(tensao>=2.50){
    digitalWrite(out1,HIGH);
  }
  else{
    digitalWrite(out1,LOW);
  }
 
 
  
 
  delay(500);

}
