#include "mecmotor.h"


mecmotor::mecmotor() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
    
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);

    pinMode(IN1_2, OUTPUT);
    pinMode(IN2_2, OUTPUT);
    pinMode(ENA_2, OUTPUT);

    pinMode(IN3_2, OUTPUT);
    pinMode(IN4_2, OUTPUT);
    pinMode(ENB_2, OUTPUT);
}


void mecmotor::forward(int speed) {
    setMotor(IN1, IN2, HIGH, LOW, ENA, speed);  
    setMotor(IN3, IN4, HIGH, LOW, ENB, speed);
    setMotor(IN1_2,IN2_2,HIGH,LOW,ENA_2,speed);
    setMotor(IN3_2,IN4_2,HIGH,LOW,ENB_2,speed); 
}


void mecmotor::backward(int speed) {
    setMotor(IN1, IN2, LOW, HIGH, ENA, speed); 
    setMotor(IN3, IN4, LOW, HIGH, ENB, speed); 
    setMotor(IN1_2,IN2_2,LOW,HIGH,ENA_2,speed);
    setMotor(IN3_2,IN4_2,LOW,HIGH,ENB_2,speed); 
}

void mecmotor::left(int speed) {
    setMotor(IN1, IN2, LOW, HIGH, ENA, speed);  
    setMotor(IN3, IN4, HIGH, LOW, ENB, speed);
    setMotor(IN1_2,IN2_2,LOW,HIGH,ENA_2,speed);
    setMotor(IN3_2,IN4_2,HIGH,LOW,ENB_2,speed); 


void mecmotor::right(int speed) {
    setMotor(IN1, IN2, HIGH, LOW, ENA, speed); 
    setMotor(IN3, IN4, LOW, HIGH, ENB, speed); 
    setMotor(IN1_2,IN2_2,HIGH,LOW,ENA_2,speed);
    setMotor(IN3_2,IN4_2,LOW,HIGH,ENB_2,speed); 


void mecmotor::stop() {
    setMotor(IN1, IN2, LOW, LOW, ENA, 0);  
    setMotor(IN3, IN4, LOW, LOW, ENB, 0);
    setMotor(IN1_2,IN2_2,LOW,LOW,ENA_2,0);
    setMotor(IN3_2,IN4_2,LOW,LOW,ENB_2,0);  
}
void mecmotor::strafer(int speed){
    setMotor(IN1, IN2, HIGH, LOW, ENA, speed);  
    setMotor(IN3, IN4, LOW, HIGH, ENB, speed);
    setMotor(IN1_2,IN2_2,LOW,HIGH,ENA_2,speed);
    setMotor(IN3_2,IN4_2,HIGH,LOW,ENB_2,speed);  
}
void mecmotor::strafel(int speed){
    setMotor(IN1, IN2, LOW, HIGH, ENA, speed);  
    setMotor(IN3, IN4, HIGH, LOW, ENB, speed);
    setMotor(IN1_2,IN2_2,HIGH,LOW,ENA_2,speed);
    setMotor(IN3_2,IN4_2,LOW,HIGH,ENB_2,speed);
}
void mecmotor::pivotfr(int speed){
    setMotor(IN1, IN2, HIGH, LOW, ENA, speed);  
    setMotor(IN3, IN4, LOW, HIGH, ENB, speed);
    setMotor(IN1_2,IN2_2,LOW,LOW,ENA_2,speed);
    setMotor(IN3_2,IN4_2,LOW,LOW,ENB_2,speed);
}
void mecmotor::pivotbr(int speed){
    setMotor(IN1, IN2, LOW, LOW, ENA, speed);  
    setMotor(IN3, IN4, LOW, LOW, ENB, speed);
    setMotor(IN1_2,IN2_2,HIGH,LOW,ENA_2,speed);
    setMotor(IN3_2,IN4_2,LOW,HIGH,ENB_2,speed);
}
void mecmotor::pivotfl(int speed){
    setMotor(IN1, IN2, LOW, HIGH, ENA, speed);  
    setMotor(IN3, IN4, HIGH, LOW, ENB, speed);
    setMotor(IN1_2,IN2_2,LOW,LOW,ENA_2,speed);
    setMotor(IN3_2,IN4_2,LOW,LOW,ENB_2,speed);
}
void mecmotor::pivotbl(int speed){
    setMotor(IN1, IN2, LOW, LOW, ENA, speed);  
    setMotor(IN3, IN4, LOW, LOW, ENB, speed);
    setMotor(IN1_2,IN2_2,LOW,HIGH,ENA_2,speed);
    setMotor(IN3_2,IN4_2,HIGH,LOW,ENB_2,speed);
}
// Helper function to control motor
void mecmotor::setMotor(int in1, int in2, bool state1, bool state2, int enPin, int speed) {
    digitalWrite(in1, state1);
    digitalWrite(in2, state2);
    analogWrite(enPin, speed);  
}
