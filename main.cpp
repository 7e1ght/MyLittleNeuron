#include <iostream>
#include <relement.h>

using namespace std;

int main()
{
    int num;
    RElement r_element;

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
//    unsigned counter = 0;
    while(1)
    {
        srand(time(0));
//        num = rand() % 10;
        cout << "Enter num: " << endl;
        cin >> num;
//        cout << "num = " << num << endl;

        r_element.setInput(numbers[num]);

        if(r_element.getResult())
        {
            cout << "yes" << endl;
            if(num != 9) r_element.incorrentNotNine();
        } else
        {
            cout << "no" << endl;
            if(num == 9) r_element.incorrectNine();
        }
//        cout << ++counter << endl;
    }
    // -1 1 -2 4 0 3 -1 -1 -2 -5 0 -1 1 1 -2
    return 0;
}
