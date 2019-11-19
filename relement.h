#ifndef RELEMENT_H
#define RELEMENT_H

#include <iostream>

namespace
{
    const int signalsNum = 15;  // Количество S-елементов
    const std::string fileName = "coef.txt"; // Файл с коэффициентами
}

class RElement
{
private:
    int coefficients[::signalsNum] = {};
    unsigned char input[::signalsNum]; // Входные сигналы

    void writeCoefficients();
public:
    void setInput(const unsigned char signals[15]);
    bool getResult();

    // Обучение
    void incorrectNine();       // Ввод девять; вывод, что не девять
    void incorrentNotNine();    // Ввод не девяти; вывод, что девять

    RElement();
};

#endif // RELEMENT_H
