#include "Random.h"
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

class Player
{
  private:
    std::string m_name{};
    std::array<int, Potion::max_potions> m_inventory{};
    int m_gold{};

  public:
    Player(std::string_view name) : m_name{name}, m_gold{Random::get(0, 100)}
    {
    }

    // getters
    std::string_view getName()
    {
        return m_name;
    }

    int getGold()
    {
        return m_gold;
    }

    std::array<int, Potion::max_potions> getInventory()
    {
        return m_inventory;
    }
};

void shop()
{
    std::cout << "Here is our selection for today:\n";

    for (auto potion : Potion::types)
    {
        std::cout << potion << ") " << Potion::name[potion] << " costs " << Potion::cost[potion] << '\n';
    }
}

Player createPlayer()
{
    std::string name{};
    std::cout << "Enter your name: ";
    std::cin >> name;

    Player player{name};

    return player;
}

void introductory()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    Player player = createPlayer();

    std::cout << "Hello, " << player.getName() << ", you have " << player.getGold() << " gold.\n\n";
}

void goodbye()
{
    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
}

int main()
{
    introductory();
    shop();
    goodbye();

    return 0;
}
