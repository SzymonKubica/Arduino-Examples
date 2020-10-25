int redComponent = 9;
int greenComponent = 10;
int blueComponent = 11;
int delayTime = 5;
int i;
int j;
int k;
void setup()
{
    pinMode(redComponent, OUTPUT);
    pinMode(greenComponent, OUTPUT);
    pinMode(blueComponent, OUTPUT);
}
void loop()
{
    for (i = 0; i < 256; i+=8)
    {
        for (j = 0; j < 256; j+=8)
        {
            for (k = 0; k < 256; k+=8)
            analogWrite(redComponent, i );
            analogWrite(greenComponent, j);
            analogWrite(blueComponent, k);
            delay(delayTime);
        }
    }
}