#include "relement.h"

using namespace std;

void RElement::writeCoefficients()
{
    coefficientsFile.open(::fileName, ios_base::out);

    for (int i =0; i < ::signalsNum; i++)
        coefficientsFile << coefficients[i] << " ";

    coefficientsFile.close();
}

unsigned char RElement::getResult()
{

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

void RElement::setInput(unsigned char* signals)
{
    for(int i = 0; i < ::signalsNum; i++)
        input[i] = signals[i];
}

RElement::RElement()
{
    coefficientsFile.open(fileName, ios_base::in);

    if(coefficientsFile.is_open())
    {
        for (int i = 0; i < ::signalsNum; i++) {
            int c;
            coefficientsFile >> c;
            coefficients[i] = c;
        }
    }

    coefficientsFile.close();
}
