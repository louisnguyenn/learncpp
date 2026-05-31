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
    Player(std::string_view name) : m_name{name}, m_gold{Random::get(80, 120)}
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

    bool spendGold(int amount)
    {
        if (amount > m_gold)
        {
            std::cout << "You don't have enough gold.\n";
            return false;
        }

        m_gold -= amount;

        return true;
    }

    void addPotion(Potion::Type type)
    {
        m_inventory[type]++;
    }
};

Player createPlayer()
{
    std::string name{};
    std::cout << "Enter your name: ";
    std::cin >> name;

    Player player{name};

    return player;
}

void printInventory(Player &player)
{
    std::cout << player.getName() << "'s Inventory:\n";
    for (auto type : player.getInventory())
    {
        std::cout << Potion::name[type] << '\n';
    }
}

void goodbye()
{
    std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
    std::exit(0);
}

void purchasePotion(Player &player)
{
    int potion_number{};

    std::cout << "Enter a potion number to purchase: ";
    std::cin >> potion_number;

    if (potion_number == 9)
    {
        printInventory(player);
        goodbye();
    }

    for (auto type : Potion::types)
    {
        if (potion_number == type)
        {
            int cost{Potion::cost[type]};

            if (player.spendGold(cost))
            {
                player.addPotion(type);
                std::cout << "You purchased a " << Potion::name[type] << "!\n";
                std::cout << "You have " << player.getGold() << " gold remaining!\n\n";
            }
        }
    }
}

void shop(Player &player)
{
    while (true)
    {
        std::cout << "Here is our selection for today:\n";

        for (auto potion : Potion::types)
        {
            std::cout << potion << ") " << Potion::name[potion] << " costs " << Potion::cost[potion] << '\n';
        }

        std::cout << "9) exit\n\n";

        purchasePotion(player);
    }
}

void introductory()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    Player player = createPlayer();

    std::cout << "Hello, " << player.getName() << ", you have " << player.getGold() << " gold.\n\n";

    shop(player);
}

int main()
{
    introductory();
    goodbye();

    return 0;
}
