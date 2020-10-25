int buzzPin = 8;
int buzzTime2;
int lightPin = A0;
int lightVal; 
int delayTime = 250;
void setup(){
    pinMode(buzzPin, OUTPUT);
    pinMode(lightPin, INPUT);
    Serial.begin(115200);
}
void loop(){
   lightVal = analogRead(lightPin); 
   Serial.println(lightVal);
}