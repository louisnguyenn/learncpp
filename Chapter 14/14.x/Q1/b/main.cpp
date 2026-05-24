#include <cmath>
#include <iostream>

class Point2d
{
  private:
    double m_x{0.0};
    double m_y{0.0};

  public:
    Point2d() = default;

    Point2d(double x, double y) : m_x{x}, m_y{y}
    {
    }

    double getX()
    {
        return m_x;
    }

    double getY()
    {
        return m_y;
    }

    void print()
    {
        std::cout << "Point2d(" << getX() << ", " << getY() << ")\n";
    }

    double distanceTo(Point2d &point2)
    {
        return std::sqrt((m_x - point2.getX())*(m_x - point2.getX()) + (m_y - point2.getY())*(m_y - point2.getY()));
    }

};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
