int fristLedPin = 8;
int secondLedPin = 9;
int thirdLedPin = 10;
int fourthLedPin = 11;
int fifthLedPin = 12;

bool isFirstDiodeOn = false;
bool isSecondDiodeOn = false;
bool isThirdDiodeOn = false;
bool isFourthDiodeOn = false;
bool isFifthDiodeOn = false;

int leftButtonPin = A1;
int centerButtonPin = A2;
int rightButtonPin = A3;
int resetButtonPin = A4;

int leftButtonStateOld = 1;
int centerButtonStateOld = 1;
int rightButtonStateOld = 1;
int resetButtonStateOld = 1;

int leftButtonStateNew;
int centerButtonStateNew;
int rightButtonStateNew;
int resetButtonStateNew;


int dt = 100;

void setup()
{
    pinMode(fristLedPin, OUTPUT);
    pinMode(secondLedPin, OUTPUT);
    pinMode(thirdLedPin, OUTPUT);
    pinMode(fourthLedPin, OUTPUT);
    pinMode(fifthLedPin, OUTPUT);

    pinMode(leftButtonPin, INPUT);
    pinMode(centerButtonPin, INPUT);
    pinMode(rightButtonPin, INPUT);
    pinMode(resetButtonPin, INPUT);
}
void loop()
{
    leftButtonStateNew = digitalRead(leftButtonPin);
    centerButtonStateNew = digitalRead(centerButtonPin);
    rightButtonStateNew = digitalRead(rightButtonPin);
    resetButtonStateNew = digitalRead(resetButtonPin);

    if (leftButtonStateNew == 0 && leftButtonStateOld ==1)
    {
        if (isFirstDiodeOn)
        {
            digitalWrite(fristLedPin, LOW);
            isFirstDiodeOn = false;
        }
        else
        {
            digitalWrite(fristLedPin, HIGH);
            isFirstDiodeOn = true;
        }

        if (isSecondDiodeOn)
        {
            digitalWrite(secondLedPin, LOW);
            isSecondDiodeOn = false;
        }
        else
        {
            digitalWrite(secondLedPin, HIGH);
            isSecondDiodeOn = true;
        }

        if (isThirdDiodeOn)
        {
            digitalWrite(thirdLedPin, LOW);
            isThirdDiodeOn = false;
        }
        else
        {
            digitalWrite(thirdLedPin, HIGH);
            isThirdDiodeOn = true;
        }
    }
    if (centerButtonStateNew == 0 && centerButtonStateOld ==1)
    {

        if (isSecondDiodeOn)
        {
            digitalWrite(secondLedPin, LOW);
            isSecondDiodeOn = false;
        }
        else
        {
            digitalWrite(secondLedPin, HIGH);
            isSecondDiodeOn = true;
        }

        if (isThirdDiodeOn)
        {
            digitalWrite(thirdLedPin, LOW);
            isThirdDiodeOn = false;
        }
        else
        {
            digitalWrite(thirdLedPin, HIGH);
            isThirdDiodeOn = true;
        }
        if (isFourthDiodeOn)
        {
            digitalWrite(fourthLedPin, LOW);
            isFourthDiodeOn = false;
        }
        else
        {
            digitalWrite(fourthLedPin, HIGH);
            isFourthDiodeOn = true;
        }
    }
    if (rightButtonStateNew == 0 && rightButtonStateOld ==1)
    {
        if (isThirdDiodeOn)
        {
            digitalWrite(thirdLedPin, LOW);
            isThirdDiodeOn = false;
        }
        else
        {
            digitalWrite(thirdLedPin, HIGH);
            isThirdDiodeOn = true;
        }
        if (isFourthDiodeOn)
        {
            digitalWrite(fourthLedPin, LOW);
            isFourthDiodeOn = false;
        }
        else
        {
            digitalWrite(fourthLedPin, HIGH);
            isFourthDiodeOn = true;
        }
        if (isFifthDiodeOn)
        {
            digitalWrite(fifthLedPin, LOW);
            isFifthDiodeOn = false;
        }
        else
        {
            digitalWrite(fifthLedPin, HIGH);
            isFifthDiodeOn = true;
        }
    }
    if(resetButtonStateNew == 0 && resetButtonStateOld==1 )
    {
        digitalWrite(fristLedPin, LOW);
        digitalWrite(secondLedPin, LOW);
        digitalWrite(thirdLedPin, LOW);
        digitalWrite(fourthLedPin, LOW);
        digitalWrite(fifthLedPin, LOW);

        isFirstDiodeOn = false;
        isSecondDiodeOn = false;
        isThirdDiodeOn = false;
        isFourthDiodeOn = false;
        isFifthDiodeOn = false;
    }
    leftButtonStateOld = leftButtonStateNew;
    centerButtonStateOld = centerButtonStateNew;
    rightButtonStateOld = rightButtonStateNew;
    resetButtonStateOld = resetButtonStateNew;
    delay(dt);

}