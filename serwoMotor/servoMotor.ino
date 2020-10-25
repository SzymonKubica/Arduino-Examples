#include <Servo.h>

int servoPin = 9;
int servoPos;
int trash;
Servo myServo;

void setup(){
    Serial.begin(115200);
    myServo.attach(servoPin);
}
void loop(){
    Serial.println("What angle for the Servo?");
    while (Serial.available()==0)
    {
    }
        servoPos = Serial.parseInt();
        trash = Serial.parseInt();
        myServo.write(servoPos);
    
}