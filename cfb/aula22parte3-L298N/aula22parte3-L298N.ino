//Controlando a velocidade do motor

#  define velm1 3
# define  m1a 4
# define m1b 5
#define pot A0

 int leitura;
  int tmp=10000;

void setup(){
  pinMode(velm1,OUTPUT);
    pinMode(m1a,OUTPUT);
    pinMode(m1b,OUTPUT);
    pinMode(pot,INPUT);
  
 
    analogWrite(velm1,0);
    digitalWrite(m1a,LOW);
    digitalWrite(m1b,LOW);
  
      
   
}

void loop(){

      leitura=map(analogRead(pot),0,1023,0,255);
      analogWrite(velm1,leitura);
      digitalWrite(m1a,HIGH);
      digitalWrite(m1b,LOW);
      
  
   
}
    
