#include <Stepper.h>
int stepsPerRevolution = 2048;
int motSpeed =10;
int dt =500;
Stepper myStepper(stepsPerRevolution, 8,10,9,11);
void setup(){
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    Serial.begin(115200);
    myStepper.setSpeed(motSpeed);
}
void loop(){
myStepper.step(stepsPerRevolution);
delay(dt);
myStepper.step(-stepsPerRevolution);
delay(dt);
}