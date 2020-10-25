#include <Servo.h>
#include "U8g2lib.h"
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

int servoPin = 7;
int servoPos = 90;
int trash;
Servo myServo;
U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g(U8G2_R0, /* clock=*/13, /* data=*/11, /* cs=*/10, /* dc=*/9, /* reset=*/8);

int trigPin = 12;
int echoPin = 10;
int pinTravelTime;
int timeOnBearingArray[181];

void draw(void)
{
    u8g.setFont(u8g_font_unifont);
    u8g.drawStr(0, 20, "Hello World");
}

void setup(void)
{

    // flip screen, if required
    //u8g.setRot180();

    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    Serial.begin(115200);
    myServo.attach(servoPin);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(112500);
}

void loop(void)
{

    // picture loop
    /* u8g.firstPage();
    do
    {
        draw();
    } while (u8g.nextPage());
    */
    for (int i = 0; i <= 180; i+=30)
    {
        myServo.write(i);
        digitalWrite(trigPin, LOW);
        delayMicroseconds(10);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);
        timeOnBearingArray[i] = pulseIn(echoPin, HIGH);
        delay(3000);
    }
    for(int time : timeOnBearingArray){
        Serial.println(time);
    }
    delay(25000);
}