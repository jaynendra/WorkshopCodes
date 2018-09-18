#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
 
int incomingByte = 0; // for incoming serial data

void setup()
{

  
motor1.setSpeed(150);   //set your motor speed acording to your motor specifications  
 motor2.setSpeed(150);
 motor3.setSpeed(150);   //set your motor speed acording to your motor specifications  
 motor4.setSpeed(150);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);

Serial.begin(9600);
}


void loop()
{

if (Serial.available() > 0) 
{
incomingByte = Serial.read();
}

switch(incomingByte)
{

case 'S': // control to stop the robot
motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
Serial.println("Stop");
incomingByte='*';
break;

case 'R': //control for right
motor1.run(FORWARD);
 motor2.run(BACKWARD);
 motor3.run(FORWARD);
 motor4.run(BACKWARD);
Serial.println("right");
incomingByte='*';
break;


case 'L': //control for left
motor1.run(BACKWARD);
 motor2.run(FORWARD);
 motor3.run(BACKWARD);
 motor4.run(FORWARD);
incomingByte='*';
break;


case 'F': //control for forward
motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);
Serial.println("right");
incomingByte='*';
break;


case 'B': //control for backward
motor1.run(BACKWARD);
 motor2.run(BACKWARD);
 motor3.run(BACKWARD);
 motor4.run(BACKWARD);
Serial.println("right");
incomingByte='*';
break;


case 'P': // pump on
digitalWrite(pump, HIGH);
Serial.println("pump on");
incomingByte='*';
break;

case 'p': // pump off
digitalWrite(pump, LOW); 
Serial.println("pump off");
incomingByte='*';
break;

case 'M':
digitalWrite(mop, HIGH); // mopper on
Serial.println("mopper on");
incomingByte='*';
break;

case 'm':
digitalWrite(mop, LOW); // mopper off
Serial.println("mopper off");
incomingByte='*';
break;

case 'U': // roller up
myServo.write(0);
Serial.println("roller up");
incomingByte='*';
break;

case 'u': // roller down
myServo.write(135);
Serial.println("roller down");
incomingByte='*';
break;


case '1':
speedy = 155;
Serial.println("speed= 10");
incomingByte='*';
break;

case '2':
speedy = 185;
Serial.println("speed= 25");
incomingByte='*';
break;

case '3':
speedy = 215;
Serial.println("speed= 75");
incomingByte='*';
break;

case '4':
speedy = 255;
Serial.println("speed= 100");
incomingByte='*';
break;

delay(5000);
}
}
