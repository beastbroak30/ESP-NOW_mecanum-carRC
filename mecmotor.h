#ifndef mecmotor_h
#define mecmotor_h

#include <Arduino.h>

class mecmotor {
public:
    mecmotor();  

   
    void forward(int speed);   
    void backward(int speed);  
    void left(int speed);       
    void right(int speed);      
    void strafer(int speed);
    void strafel(int speed);
    void pivotfr(int speed);
    void pivotfl(int speed);
    void pivotbr(int speed);
    void pivotbl(int speed);
    void stop();               
private:
    
    const int IN1 = 18;  
    const int IN2 = 19; 
    const int ENA = 21;  

    const int IN3 = 5; 
    const int IN4 = 23; 
    const int ENB = 22; 

    const int IN1_2 = 13;
    const int IN2_2 = 12;
    const int ENA_2 = 14;

    const int ENB_2 = 15;
    const int IN3_2 = 2;
    const int IN4_2 = 4;


   
    void setMotor(int in1, int in2, bool state1, bool state2, int enPin, int speed);
};

#endif
