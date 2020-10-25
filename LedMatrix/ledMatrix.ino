//Shift register pins
int latchPin = 11;
int clockPin = 10;
int dataPin = 12;
//Ground pins for the matrix
int firstGND = 2;
int secondGND = 3;
int thirdGND = 4;
int fourthGND = 5;
int fifthGND = 6;
int sixthGND = 7;
int seventhGND = 8;
int eighthGND = 9;
//delay intervals
int delayInterval = 10;
//the abstract representation of the matrix itself
int matrixTest[8][8];
//Pins for the analog stick;
int XPin = A0;
int YPin = A1;
int SPin = A2;

int Xval;
int Yval;
int Sval;

int switchStateNew;
int switchStateOld = 1;

bool isButtonActive = true;
int stickDirection(int Xval, int Yval)
{
    if (Xval == 0)
    {
        return 0; // condition for up
    }
    if (Yval == 0)
    {
        return 1; // condition for right
    }
    if (Xval > 1000)
    {
        return 2; // condition for down
    }
    if (Yval > 1000)
    {
        return 3; // condition for left
    }
    return 4;
}

void lightMatrix(int matrix[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(i + 2, LOW);
        int shiftRegisterInput = 0;
        for (int j = 0; j < 8; j++)
        {
            if (matrix[i][j] == 1)
            {
                switch (j)
                {
                case 0:
                    shiftRegisterInput += 128;
                    break;
                case 1:
                    shiftRegisterInput += 64;
                    break;
                case 2:
                    shiftRegisterInput += 32;
                    break;
                case 3:
                    shiftRegisterInput += 16;
                    break;
                case 4:
                    shiftRegisterInput += 8;
                    break;
                case 5:
                    shiftRegisterInput += 4;
                    break;
                case 6:
                    shiftRegisterInput += 2;
                    break;
                case 7:
                    shiftRegisterInput += 1;
                    break;
                }
            }
        }
        digitalWrite(latchPin, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, shiftRegisterInput);
        digitalWrite(latchPin, HIGH);

        delay(delayInterval);

        digitalWrite(firstGND, HIGH);
        digitalWrite(secondGND, HIGH);
        digitalWrite(thirdGND, HIGH);
        digitalWrite(fourthGND, HIGH);
        digitalWrite(fifthGND, HIGH);
        digitalWrite(sixthGND, HIGH);
        digitalWrite(seventhGND, HIGH);
        digitalWrite(eighthGND, HIGH);
    }
}
void setup()
{
    pinMode(latchPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(firstGND, OUTPUT);
    pinMode(secondGND, OUTPUT);
    pinMode(thirdGND, OUTPUT);
    pinMode(fourthGND, OUTPUT);
    pinMode(fifthGND, OUTPUT);
    pinMode(sixthGND, OUTPUT);
    pinMode(seventhGND, OUTPUT);
    pinMode(eighthGND, OUTPUT);

    pinMode(XPin, INPUT);
    pinMode(YPin, INPUT);
    pinMode(SPin, INPUT);

    digitalWrite(firstGND, HIGH);
    digitalWrite(secondGND, HIGH);
    digitalWrite(thirdGND, HIGH);
    digitalWrite(fourthGND, HIGH);
    digitalWrite(fifthGND, HIGH);
    digitalWrite(sixthGND, HIGH);
    digitalWrite(seventhGND, HIGH);
    digitalWrite(eighthGND, HIGH);
    digitalWrite(SPin, HIGH);
    Serial.begin(115200);
}
void loop()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            matrixTest[i][j] = 0;
        }
    }
    int xPos = 1;
    int yPos = 0;

    matrixTest[yPos][xPos] = 1;

    switchStateNew = digitalRead(SPin);
    Serial.println(switchStateNew);
    if (switchStateNew == 0 && switchStateOld == 1)
    {
        if (isButtonActive)
        {
            isButtonActive = false;
        }
        else
        {
            isButtonActive = true;
        }
    }
    switchStateOld = switchStateNew;

    while (isButtonActive)
    {
        matrixTest[yPos][xPos] = 0;
        switchStateNew = digitalRead(SPin);
        if (switchStateNew == 0 && switchStateOld == 1)
        {
            if (isButtonActive)
            {
                isButtonActive = false;
            }
            else
            {
                isButtonActive = true;
            }
        }
        Xval = analogRead(XPin);
        Yval = analogRead(YPin);
        //Serial.println(stickDirection(Xval, Yval));

        switchStateOld = switchStateNew;
        if (stickDirection(Xval, Yval) == 0)
        {
            if (yPos > 0)
                yPos--;
        }
        else if (stickDirection(Xval, Yval) == 1)
        {
            if (xPos < 7)
                xPos++;
        }
        else if (stickDirection(Xval, Yval) == 2)
        {
            if (yPos < 7)
                yPos++;
        }
        else if (stickDirection(Xval, Yval) == 3)
        {
            if (xPos > 1)
                xPos--;
        }
        matrixTest[yPos][xPos] = 1;

        lightMatrix(matrixTest);
    }
}