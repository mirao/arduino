/*
    Formatted printing of stuff like voltage into console
*/

#ifndef PrintFormat_h
#define PrintFormat_h

class PrintFormat
{
    public:
        void printVoltage(int pin);
    private:
        static constexpr double _voltageDiv = 5.0 / 1024;
};

#endif