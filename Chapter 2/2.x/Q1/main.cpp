#include <iostream>

int readNumber()
{
    std::cout << "Enter a number: ";

    int input{};
    std::cin >> input;

    return input;
}

void writeAnswer(int answer)
{
    std::cout << "Answer: " << answer << '\n';
}


int main()
{
    int num1{readNumber()};
    int num2{readNumber()};

    int answer{num1 + num2};

    writeAnswer(answer);

    return 0;
}