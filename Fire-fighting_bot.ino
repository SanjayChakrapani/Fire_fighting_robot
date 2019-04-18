// Use the Fire fighting app to control
// Created by Sanjay Chakrapani (EEK)

#include <SoftwareSerial.h>

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

SoftwareSerial BT(2, 3); //TX, RX respetively of BT module
int read_val;
int S_val;

int a1 = 4; //right motor
int a2 = 5;
int b1 = 6; //left motor
int b2 = 7;

int pump = 8; // connect relay to drive pump motor 

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
 myservo.attach(9); //connect servo to pin 9
 myservo.write(90);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(pump, OUTPUT);
  
  digitalWrite(pump, 0);
  digitalWrite(a1, 0);
  digitalWrite(a2, 0);
  digitalWrite(b1, 0);
  digitalWrite(b2, 0);
}
 
void loop() {

 if (BT.available() > 0) {
  read_val = BT.read(); //Conduct a serial read 
  Serial.println(read_val);
    
  if(read_val == 2){
   digitalWrite(pump, 1);
  }
  
  else if(read_val == 1){
   digitalWrite(pump, 0);  
  }
   
  else if(read_val == 3){
   digitalWrite(a1, 1);
   digitalWrite(a2, 0);
   digitalWrite(b1, 1);
   digitalWrite(b2, 0);
  }
  else if(read_val == 04){
   digitalWrite(a1, 0);
   digitalWrite(a2, 1);
   digitalWrite(b1, 0);
   digitalWrite(b2, 1);
  }
  else if(read_val == 6){
   digitalWrite(a1, 1);
   digitalWrite(a2, 0);
   digitalWrite(b1, 0);
   digitalWrite(b2, 1);
  }
  else if(read_val == 5){
   digitalWrite(a1, 0);
   digitalWrite(a2, 1);
   digitalWrite(b1, 1);
   digitalWrite(b2, 0);
  }
  else if(read_val == 7){
   digitalWrite(a1, 0);
   digitalWrite(a2, 0);
   digitalWrite(b1, 0);
   digitalWrite(b2, 0);
  }
  
  else if(read_val > 7){ // slider value starts from 8 to 180
   S_val = read_val;
   S_val = map(S_val, 8, 180, 5, 180); //mapped to rotate 0 to 180
   myservo.write(S_val);
   Serial.print("mapped");
   Serial.println(S_val);
   delay(15);
  }

  }
 } 
