int triggerPin = 5;
int echoPin = 6;
int buzzPin = 7;
int buzzTime;
long duration, distance;

long MicrosecondsToCentimeters(long duration)
{
    long d = (duration / 2) * .0343;
    return d;
}

void setup()
{
    Serial.begin(115200);
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}

void loop()
{
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = MicrosecondsToCentimeters(duration);
    Serial.print("Distance : ");
    Serial.println(distance);
    buzzTime = distance;
    digitalWrite(buzzPin, HIGH);
    delay(buzzTime);
    digitalWrite(buzzPin, LOW);
    delay(buzzTime);
}
