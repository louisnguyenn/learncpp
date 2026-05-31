#include <iostream>

class Fraction
{
  private:
    int m_numerator{};
    int m_denominator{};

  public:
    Fraction(int numerator, int denominator) : m_numerator{numerator}, m_denominator{denominator}
    {
    }

    void print()
    {
        std::cout << m_numerator << '/' << m_denominator << '\n';
    }

    // friend Fraction operator/(Fraction &f1, Fraction &f2);
};

// Fraction operator/(Fraction &f1, Fraction &f2)
// {

// }

int main()
{
    Fraction f1{1, 4};
    f1.print();

    Fraction f2{1, 2};
    f2.print();

    return 0;
}