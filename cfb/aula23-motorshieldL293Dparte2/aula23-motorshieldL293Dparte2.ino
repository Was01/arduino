# include<AFMotor.h>


AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

void setup() {
  motor1.setSpeed(0);
  motor2.setSpeed(0);

}

void loop() {
  
  motor1.setSpeed(255);
  motor1.run(FORWARD); //sentido horário
  motor2.setSpeed(255);
  motor2.run(BACKWARD); //sentido anti-horário
  delay(30000);

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  delay(2000);

  motor1.setSpeed(255);
  motor1.run(BACKWARD); //sentido anti-horário
  motor2.setSpeed(255);
  motor2.run(FORWARD); //sentido horário
  delay(30000);

  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  delay(2000);

  
}
