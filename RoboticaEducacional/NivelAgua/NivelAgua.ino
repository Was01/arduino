// C++ code
//
void setup(){
  //declaração de pinos
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  
}

void loop(){
  int nivelAgua=70;
  if (nivelAgua<30){
    digitalWrite(8,HIGH);
   	digitalWrite(9,LOW);
  	digitalWrite(10,LOW);
  }
  
   if (nivelAgua<60  && nivelAgua>=30){
     digitalWrite(9,HIGH);
     digitalWrite(8,LOW);
     digitalWrite(9,LOW);
  }
  
    if (nivelAgua<100 && nivelAgua>=60){
    	digitalWrite(10,HIGH);
       	digitalWrite(8,LOW);
  		digitalWrite(9,LOW);
  	}
  
}
