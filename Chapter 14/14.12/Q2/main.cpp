#include <iostream>
#include <string>
#include <string_view>

class Ball
{
  private:
    std::string m_color{"black"};
    double m_radius{10.0};

  public:
    Ball(double radius) : Ball("black", radius)
    {
    }

    Ball(std::string color="black", double radius=10.0) : m_color{color}, m_radius{radius}
    {
        print();
    }

    std::string_view getColor()
    {
        return m_color;
    }

    double getRadius()
    {
        return m_radius;
    }

    void print()
    {
        std::cout << "Ball(" << getColor() << ", " << getRadius() << ")" << '\n';
    }
};

int main()
{
    Ball def{};
    Ball blue{"blue"};
    Ball twenty{20.0};
    Ball blueTwenty{"blue", 20.0};

    return 0;
}
