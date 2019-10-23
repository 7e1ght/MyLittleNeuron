#ifndef RELEMENT_H
#define RELEMENT_H

#include <fstream>

namespace
{
    const int signalsNum = 15;  // Количество S-елементов
    const std::string fileName = "coef.txt"; // Файл с коэффициентами
}

class RElement
{
private:
    std::fstream coefficientsFile;
    int coefficients[::signalsNum];
    unsigned char input[::signalsNum]; // Входные сигналы

    void writeCoefficients();
public:
    void setInput(unsigned char* signals);
    unsigned char getResult();

    // Обучение
    void incorrectNine();       // Ввод девять; вывод, что не девять
    void incorrentNotNine();    // Ввод не девяти; вывод, что девять

    RElement();
};

#endif // RELEMENT_H
