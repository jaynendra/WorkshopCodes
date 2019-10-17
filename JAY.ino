
#include <AFMotor.h>


AF_DCMotor motor1(2, MOTOR12_1KHZ); 
AF_DCMotor motor2(4, MOTOR12_1KHZ); 


char command; 

void setup() 
{       
  Serial.begin(9600);  
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); 
  
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    }
  } 
}

void forward()
{
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
  motor1.run(FORWARD); 
 
}

void back()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(BACKWARD); 
}

void left()
{
  motor1.setSpeed(255); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(255); 
  motor2.run(FORWARD); 
   
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  
}
