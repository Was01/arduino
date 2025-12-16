// C++ code


#define btn 2
#define led 8

int flag=0;

void setup()
{
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
  pinMode(led,OUTPUT);
  
 
}

void loop()
{
  int leitura=!digitalRead(btn);
  if (leitura){
    flag=1;
  }
    if(!leitura && flag==1){
  		digitalWrite(led,!digitalRead(led));
    	flag=0;
  	}
  
}
