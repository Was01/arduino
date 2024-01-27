
# include<AFMotor.h>


AF_DCMotor motor1(3);

void setup() {
  motor1.setSpeed(0);

}

void loop() {
  
  motor1.setSpeed(255);
  motor1.run(FORWARD); //sentido horário
  delay(30000);

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  delay(2000);

  motor1.setSpeed(255);
  motor1.run(BACKWARD); //sentido anti-horário
  delay(30000);

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  delay(2000);

}
