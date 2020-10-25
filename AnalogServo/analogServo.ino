#include <Servo.h>
int Xpin = A1;
int Ypin = A0;
int Spin = 6;
int Xval;
int Yval;
int Sval;
int dt = 20;
// Servo Pins
int ServoPower = 10;
int ServoControl = A4;
Servo myServo;
double angle;
void setup()
{
    Serial.begin(115200);
    pinMode(Xpin, INPUT);
    pinMode(Ypin, INPUT);
    pinMode(Spin, INPUT);
    myServo.attach(ServoControl);
    pinMode(ServoPower, OUTPUT);
    pinMode(ServoControl, OUTPUT);

    digitalWrite(ServoPower, HIGH);
}
void loop()
{
    Xval = analogRead(Xpin);
    Yval = analogRead(Ypin);
    Sval = digitalRead(Spin);
    delay(dt);

    Serial.print("X value = ");
    Serial.print(Xval);
    Serial.print(" Y value = ");
    Serial.print(Yval);
    Serial.print(" Switch state is ");
    Serial.println(Sval);
    angle = (double) Xval / 1023 * 180;
    Serial.println(angle);
    myServo.write(round(angle));
}