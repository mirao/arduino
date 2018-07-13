/*
    Show count of rotary encoder turns
    * Positive count means clockwise rotating, negative count means counter clockwise rotating
    * Push button clears of counter
    
    Stuff:
        - breadboard
        - rotary encoder with push button: https://www.aliexpress.com/item/Free-Shipping-360-rotary-encoder-FOR-Module-Electronic-Component/1000001872933.html?spm=a2g0s.9042311.0.0.7fb94c4dlnj18B
        - 2 capacitors 100 nF (for debouncing, see https://www.allaboutcircuits.com/projects/how-to-use-a-rotary-encoder-in-a-mcu-based-project/)
        - 2 resistors 20 kOhm (for debouncing)

    Schema:
        A0 <-> SW

        A1 <-> Cap1 <-> GND
        |
        Res1
        |
        CLK
                
        A2 <-> Cap2 <-> GND
        |
        Res2
        |
        DT
*/

const int SW = A0; // Push button on encoder, used for clearing of counter. LOW means pushed.
const int CLK = A1; // CLK output from encoder connected to Arduino's A1 input
const int DT = A2; // DT output from encoder connected to Arduino's A2 input

class RotaryEncoder
{
    private:
        int count; // Counter value
        int prevClk; // Previous voltage level (LOW/HIGH) of CLK output in rotary encoder
        int getCnt();
    public:
        RotaryEncoder(int);
        void resetCnt(int);
        void decCnt();
        void incCnt();
        void printCnt();
        int getCurrentClk();
        int getPrevClk();
        void setPrevClk(int);
        int getCurrentDt();
        int getSw();
};

// Set initial count
RotaryEncoder::RotaryEncoder(int count)
{
    pinMode(SW, INPUT);
    pinMode(CLK, INPUT);
    pinMode(DT, INPUT);
    resetCnt(count);
    setPrevClk(getCurrentClk());
}

int RotaryEncoder::getCnt()
{
    return count;
}

void RotaryEncoder::decCnt()
{
    count--;
}

void RotaryEncoder::incCnt()
{
    count++;
}

void RotaryEncoder::resetCnt(int newCount)
{
    count = newCount;
}

void RotaryEncoder::printCnt()
{
    Serial.print("Counter: ");
    Serial.println(getCnt());
}

int RotaryEncoder::getCurrentClk()
{
    return digitalRead(CLK);    
}

int RotaryEncoder::getPrevClk()
{
    return prevClk;    
}

void RotaryEncoder::setPrevClk(int voltage)
{
    prevClk = voltage;    
}

int RotaryEncoder::getCurrentDt()
{
    return digitalRead(DT);
}

int RotaryEncoder::getSw()
{
    return digitalRead(SW);
}

RotaryEncoder rotaryEncoder(0);

void setup() {
    Serial.begin(9600);
}

void loop() {
    int currentClk = rotaryEncoder.getCurrentClk();
    int prevClk = rotaryEncoder.getPrevClk();
    int sw = rotaryEncoder.getSw();

    if (sw == LOW) { // Button is pushed
        rotaryEncoder.resetCnt(0);
    }
    if (currentClk < prevClk) {
        // Potentiometer turned
        int currentDt = rotaryEncoder.getCurrentDt();
        if (currentDt == currentClk) {
            // Clockwise rotating
            rotaryEncoder.incCnt();
        } else {
            // Counter clockwise rotating
            rotaryEncoder.decCnt();
        }
        rotaryEncoder.printCnt();
    }
    rotaryEncoder.setPrevClk(currentClk);
}