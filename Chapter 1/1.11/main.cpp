#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";

    int num{};
    std::cin >> num;

    int double_num{num * 2};
    std::cout << "Double that number is: " << double_num << '\n';
    
    return 0;
}