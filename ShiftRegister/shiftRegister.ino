int latchPin = 11;
int clockPin = 9;
int dataPin = 12;
int dt = 1000;

byte LEDs=0x00;
void setup(){
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    Serial.begin(115200);

}
void loop(){
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
    digitalWrite(latchPin, HIGH);
    delay(dt);
    if(LEDs==0xFF){
        LEDs = 0x00;
    }else{
    LEDs++;
    }
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
    digitalWrite(latchPin, HIGH);

}