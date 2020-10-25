int readPin = A3;
int responseLed = 9;
int delayTime = 50;
float V2 = 0;
int readVal;

void setup(){
    pinMode(readPin, INPUT);
    pinMode(responseLed, OUTPUT);
    Serial.begin(115200);
}
void loop(){
    readVal = analogRead(readPin);
    V2 = (255./1023.)*readVal;
    Serial.println(V2);
    analogWrite(responseLed,255-V2);
    delay(delayTime);
}