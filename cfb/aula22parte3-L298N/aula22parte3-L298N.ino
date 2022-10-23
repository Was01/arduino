//Controlando a velocidade do motor

#  define velm1 3
# define  m1a 4
# define m1b 5

 int max=255;
 int i=255;
  int tmp=5000;

void setup(){
  pinMode(velm1,OUTPUT);
    pinMode(m1a,OUTPUT);
    pinMode(m1b,OUTPUT);
  
 
    analogWrite(velm1,0);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);
  
      
   
}

void loop(){

   
      analogWrite(velm1,i);
      digitalWrite(m1a,HIGH);
      digitalWrite(m1b,LOW);
      delay(tmp);
      analogWrite(velm1,i);
      digitalWrite(m1a,LOW);
      digitalWrite(m1b,LOW);
      delay(tmp);
      analogWrite(velm1,i-85);
      digitalWrite(m1a,LOW);
      digitalWrite(m1b,HIGH);
      delay(tmp);
      analogWrite(velm1,i);
      digitalWrite(m1a,LOW);
      digitalWrite(m1b,LOW);
      delay(tmp);
      
    

  
  
   
}
    
