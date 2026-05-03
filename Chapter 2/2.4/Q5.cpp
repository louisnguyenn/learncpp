#include <iostream>

int doubleNumber(int num)
{
    return num * 2;
}

int main()
{
    std::cout << "Enter an integer: ";

    int num{};
    std::cin >> num;

    int num_doubled{doubleNumber(num)};
    std::cout << "Doubled Number: " << num_doubled << '\n';

    return 0;
}