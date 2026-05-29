#include <cassert>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace Items
{
enum Type
{
    health_potion,
    torches,
    arrows,
    max_items
};
} // namespace Items

int countTotalItems(std::vector<int> &inventory)
{
    int sum{0};

    for (auto item : inventory)
    {
        sum += item;
    }

    return sum;
}

int countHealthPotion(std::vector<int> &inventory)
{
    return inventory[Items::health_potion];
}

int countTorches(std::vector<int> &inventory)
{
    return inventory[Items::torches];
}

int countArrows(std::vector<int> &inventory)
{
    return inventory[Items::arrows];
}

int main()
{
    std::vector inventory{1, 5, 10};
    assert(std::size(inventory) == Items::max_items);

    if (countHealthPotion(inventory) == 1)
    {
        std::cout << "You have " << countHealthPotion(inventory) << " health potion\n";
    }
    else
    {
        std::cout << "You have " << countHealthPotion(inventory) << " health potions\n";
    }

    if (countTorches(inventory) == 1)
    {
        std::cout << "You have " << countTorches(inventory) << " torch\n";
    }
    else
    {
        std::cout << "You have " << countTorches(inventory) << " torches\n";
    }

    if (countArrows(inventory) == 1)
    {
        std::cout << "You have " << countArrows(inventory) << " arrow\n";
    }
    else
    {
        std::cout << "You have " << countArrows(inventory) << " arrows\n";
    }

    if (countTotalItems(inventory) == 1)
    {
        std::cout << "You have " << countTotalItems(inventory) << " total item\n";
    }
    else
    {
        std::cout << "You have " << countTotalItems(inventory) << " total items\n";
    }

    return 0;
}
