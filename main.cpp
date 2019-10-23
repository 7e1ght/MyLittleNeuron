#include <iostream>
#include <relement.h>

using namespace std;

int main()
{
    int num;
    RElement r_element;
    char answer;

    const unsigned char numbers[10][15] =
    {
        {1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1},  // 0
        {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},  // 1
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},  // 2
        {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1},  // 3
        {1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1},  // 4
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},  // 5
        {1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},  // 6
        {1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1},  // 7
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},  // 8
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1}   // 9
    };

    while(1)
    {
        cout << "Enter number: ";
        cin >> num;

        r_element.setInput(numbers[num]);

        if(r_element.getResult())
        {
            cout << "It's 9" << endl;
            cin >> answer;
        } else {
            cout << "It is not 9" << endl;
            cin >> answer;
        }

        if(answer == 'n' && num == 9) r_element.incorrectNine();
        else if(answer == 'n' && num != 9) r_element.incorrentNotNine();
    }

    return 0;
}
