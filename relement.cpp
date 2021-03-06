#include "relement.h"

#include <fstream>

using namespace std;

void RElement::writeCoefficients()
{
    ofstream coefficientsFile(::fileName, ios::binary);

    coefficientsFile.write((char*)coefficients, sizeof (coefficients));

    coefficientsFile.close();
}

bool RElement::getResult()
{
    int sum = 0;

    for(int i = 0; i < ::signalsNum; i++)
        sum += input[i] * coefficients[i];

    // Функция активации - единичная ступенька
    if(sum < 0) return false;
    else return true;
}

void RElement::incorrentNotNine()
{
    for(int i = 0; i < ::signalsNum; i++)
        if(input[i] == 1)
        {
            coefficients[i] -= 1;
            writeCoefficients();
        }

    writeCoefficients();
}

void RElement::incorrectNine()
{
    for(int i = 0; i < ::signalsNum; i++)
        if(input[i] == 1)
        {
            coefficients[i] += 1;
            writeCoefficients();
        }

    writeCoefficients();
}

void RElement::setInput(const unsigned char signals[15])
{
    for(int i = 0; i < ::signalsNum; i++)
        input[i] = signals[i];
}

RElement::RElement()
{
    ifstream coefficientsFile(::fileName, ios::binary);

    if(coefficientsFile.is_open())
    {
        coefficientsFile.read((char*)&coefficients, sizeof (coefficients));
    }
    else {
        for (int i = 0; i < ::signalsNum; i++)
            coefficients[i] = 0;
    }

    coefficientsFile.close();
}
