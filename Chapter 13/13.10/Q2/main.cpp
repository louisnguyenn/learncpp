#include <iostream>

struct Fraction
{
    int numerator{};
    int denominator{};
};

Fraction readFraction()
{
    Fraction input{};

    std::cout << "Enter a value for the numberator: ";
    std::cin >> input.numerator;

    std::cout << "Enter a value for the denominator: ";
    std::cin >> input.denominator;

    return input;
}

Fraction multiplyFraction(Fraction &fraction1, Fraction &fraction2)
{
    Fraction result{fraction1.numerator * fraction2.numerator, fraction1.denominator * fraction2.denominator};

    return result;
}

void printFraction(Fraction &fraction)
{
    std::cout << fraction.numerator << "/" << fraction.denominator;
}

int main()
{
    Fraction fraction1{readFraction()};
    Fraction fraction2{readFraction()};

    Fraction result{multiplyFraction(fraction1, fraction2)};

    std::cout << "Your fractions multiplied together: ";
    printFraction(result);
    std::cout << '\n';

    return 0;
}