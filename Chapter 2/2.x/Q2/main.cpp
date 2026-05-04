#include <iostream>

int readNumber();
void writeAnswer(int answer);

int main()
{
    int num1{readNumber()};
    int num2{readNumber()};

    int answer{num1 + num2};

    writeAnswer(answer);

    return 0;
}