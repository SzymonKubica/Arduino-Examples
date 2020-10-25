int lightPin = A0;
int lightVal;
int buzzPin = 8;
int dt = 100;
int brotherIsRunningPin = A3;
int brotherVal;

void setup(){
    pinMode(lightPin, INPUT);
    pinMode(brotherIsRunningPin, INPUT);
    pinMode(buzzPin, OUTPUT);
    Serial.begin(115200);

}
void loop(){
    brotherVal = digitalRead(brotherIsRunningPin);
    lightVal = analogRead(lightPin);
    if(brotherVal == HIGH){
        if(lightVal<1000){
            digitalWrite(buzzPin, HIGH);
            Serial.print("1");
        }else{
            digitalWrite(buzzPin, LOW);
            Serial.print("0");
        }

    }
    delay(dt);
    
}