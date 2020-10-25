int readPin = A3;
int V2 = 0;
int time = 500;
void setup(){
    pinMode(readPin, INPUT);
    Serial.begin(9600);
}
void loop(){
    V2 = analogRead(readPin);
    Serial.println(V2);
    delay(time);
}
