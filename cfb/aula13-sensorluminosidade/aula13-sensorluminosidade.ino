
# define led 3
# define ldr A0

int vldr=0;


void setup() {
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
  Serial.begin(9600);
  

}

void loop() {
  
 vldr=analogRead(ldr);
 if (vldr<150){
    digitalWrite(led,HIGH);
  }else{
    digitalWrite(led,LOW);
    }
 delay(500);
  Serial.println(vldr);

}
