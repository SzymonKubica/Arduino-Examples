int buzzPin = 8;
double buzzTime2;
int lightPin = A0;
int lightVal;
int delayTime = 500;
void setup(){
    pinMode(buzzPin, OUTPUT);
    pinMode(lightPin, INPUT);
    Serial.begin(115200);
}
void loop(){
    lightVal = analogRead(lightPin); 
    Serial.println(lightVal);
    buzzTime2 = -(398/68)*lightVal+4293;
    digitalWrite(buzzPin, HIGH);
    delayMicroseconds(buzzTime2);
    digitalWrite(buzzPin, LOW);
    delayMicroseconds(buzzTime2);
}