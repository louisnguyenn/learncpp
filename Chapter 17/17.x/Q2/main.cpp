#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Potion
{
enum Type
{
    healing,
    mana,
    speed,
    invisibility,
    max_potions
};

std::array types{healing, mana, speed, invisibility};
std::array<int, max_potions> cost{20, 30, 12, 50};
std::array<std::string_view, max_potions> name{"healing", "mana", "speed", "invisibility"};
} // namespace Potion

void shop()
{
    std::cout << "Here is our selection for today:\n";

    for (auto potion : Potion::types)
    {
        std::cout << potion << ") " << Potion::name[potion] << " costs " << Potion::cost[potion] << '\n';
    }
}

int main()
{
    shop();

    return 0;
}
