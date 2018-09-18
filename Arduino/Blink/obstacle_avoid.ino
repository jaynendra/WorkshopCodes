/*
 obstacle avoider robot:
   An Obstacle Avoidance Robot is an intelligent robot, 
   which can automatically sense and overcome obstacles on its path. 
   It contains of a Microcontrollk8er to process the data, 
   and Ultrasonic sensors to detect the obstacles on its path. 
   Obstacle avoidance is one of the most important aspects of mobile robotics.
   HARDWARE REQUIRED:-
   ARDUINO UNO:-1
   POWER CABLE:-1
   ADAFRUIT MOTOR DRIVER SHIELD:-1
   DC GEARED MOTOR:-4 you can also use 2 motors
   ultrasonic SENSORS:-1
   CHASSIS:-1
   WHEELS:-4
   CASTER WHEEL:-1
   JUMPER WIRE:-6
   BATTERY(18650):-2
    The circuit:
    -analog 1 (A0): output pin for trig
    -analog 2 (A1): input pin for echo
    -servo : output pin A3
    -motor1: output pin for motor1
    -motor2: output pin for motor2
    -motor3: output pin for motor3
    -motor4: output pin for motor4
    
   created and developed at 05 sept 2018
   by Jaynendra sharma
   
*/
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
#include<Servo.h>
Servo SM;


#define ENA A3
#define ENB 3

#define trigpin 0
#define echo 1

void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(150);   //set your motor speed acording to your motor specifications  
 motor2.setSpeed(150);
 motor3.setSpeed(150);
 motor4.setSpeed(150);
 motor1.run(RELEASE); 
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigpin, OUTPUT);
  pinMode(echo, INPUT);

  analogWrite(ENA, 220);
  analogWrite(ENB, 240);

  SM.attach(9);
  SM.write(90);
  delay(3000);


}
int distance;
void loop() {
  // put your main code here, to run repeatedly:
  findDistance() ;

  if (distance > 35) {
    forward();
  } else {
    delay(60);
    findDistance();
    if (distance > 35) {
      forward();             // forward direction
    } else {
      Stop();
      SM.write(40);
      delay(500);
      findDistance();
      if (distance>35){
        SM.write(90);
        delay(1000);
        rightward();     // right direction
        delay(500);
        Stop();
      }else{
        SM.write(130);
        delay(1000);
        findDistance();
        if (distance>35){
          SM.write(90);
          delay(1000);
          leftward();      //leftward direction
          delay(500);
          Stop();         //stop
        }else{
          SM.write(90);
          delay(1000);
          rightward();
          delay(1500);
          Stop();
          
        }
      }
    }
  }
}
void forward() {            //function for forward direction
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void backward() {           //function for backward direction
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void leftward() {             //function for leftward direction     
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void rightward() {           //function for rightward direction
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void Stop() {               //function for stop direction
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void findDistance() {         // function for distance measure
  int duration;
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echo, HIGH);
  distance = (1 / 29.1) * (duration / 2);
  delay(60);

}

