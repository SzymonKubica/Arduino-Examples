#include <DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 500;

void setup(){
    Serial.begin(9600);
    HT.begin();
    delay(setTime);
}
void loop(){
    humidity = HT.readHumidity();
    tempC = HT.readTemperature();
    tempF = HT.readTemperature(true);
    
    Serial.println("The humidity is " );
    Serial.println(humidity);
    Serial.println("The temperature in celsius is " );
    Serial.println(tempC);
    Serial.println("The temperature in fahrenheit is " );
    Serial.println(tempF);

    delay(2000);

}