#define ledR 2
#define ledG 3
#define ledB 4


void setup() {
  // put your setup code here, to run once:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledR,HIGH); 
  digitalWrite(ledG,LOW); 
  digitalWrite(ledB,LOW);
  delay(3000);
   digitalWrite(ledR,LOW); 
  digitalWrite(ledG,HIGH); 
  digitalWrite(ledB,LOW);
  delay(3000);
  digitalWrite(ledR,LOW); 
  digitalWrite(ledG,LOW); 
  digitalWrite(ledB,HIGH);
  delay(3000);

}
