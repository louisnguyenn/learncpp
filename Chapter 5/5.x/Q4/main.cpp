#include <iostream>
#include <string>

int main()
{
    std::cout << "Enter the name of person #1: ";

    std::string person1{};
    std::getline(std::cin >> std::ws, person1);

    std::cout << "Enter the age of " << person1 << " : ";

    int age1{};
    std::cin >> age1;

    std::cout << "Enter the name of person #2: ";

    std::string person2{};
    std::getline(std::cin >> std::ws, person2);

    std::cout << "Enter the age of " << person2 << " : ";

    int age2{};
    std::cin >> age2;

    if (age2 > age1)
    {
        std::cout << person2 << " (age " << age2 << ") is older than " << person1 << " (age " << age1 << ")" << '\n';
    }
    else
    {
        std::cout << person1 << " (age " << age1 << ") is older than " << person2 <<  "(age " << age2 << ")" << '\n';
    }

    return 0;
}