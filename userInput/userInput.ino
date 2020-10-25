int myNumber;
int leftOver;
int redLed = 9;
String msg = "Please enter your number";
String msg2 = "Your number is: ";

void setup(){
    Serial.begin(115200);
    pinMode(redLed, OUTPUT);
}
void loop(){
    Serial.println(msg);
    while(Serial.available()==0){

    }
    myNumber = Serial.parseInt();
    Serial.println(msg2 + myNumber);
    leftOver = Serial.parseInt();
    if(myNumber>=0 && myNumber<256){
        analogWrite(redLed, myNumber);
    }else{
        analogWrite(redLed, 0);
    }
}