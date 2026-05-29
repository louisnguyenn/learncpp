#include <iostream>
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

    for (auto item: inventory)
    {
        sum += item;
    }

    return sum;
}

int main()
{
    std::vector inventory{1, 5, 10};

    std::cout << "You have " << countTotalItems(inventory) << " total items\n";

    return 0;
}
