#include <array>
#include <iostream>
#include <string>
#include <string_view>

namespace Animal
{
enum Type
{
    chicken,
    dog,
    cat,
    elephant,
    duck,
    snake,
    max_animals
};

struct Data
{
    std::string_view name{};
    int num_legs{};
    std::string_view sound{};
};

std::array<Animal::Data, Animal::max_animals> animal_data{{{"chicken", 2, "cluck"},
                                                           {"dog", 4, "woof"},
                                                           {"cat", 4, "meow"},
                                                           {"elephant", 4, "trumpet"},
                                                           {"duck", 2, "quack"},
                                                           {"snake", 0, "hiss"}}};

static_assert(Animal::max_animals == std::size(animal_data));
} // namespace Animal

void printData(std::array<Animal::Data, Animal::max_animals> &data, std::string_view user_animal)
{
    int found{0};
    for (auto &animal : data)
    {
        if (animal.name == user_animal)
        {
            std::cout << "A " << animal.name << " has " << animal.num_legs << " legs and says " << animal.sound
                      << "\n\n";
            found = 1;
        }
    }

    if (found == 0)
    {
        std::cout << "That animal couldn't be found.\n\n";
    }

    std::cout << "Here is the data for the rest of the animals:\n";
    for (auto &animal : data)
    {
        if (animal.name != user_animal)
        {
            std::cout << "A " << animal.name << " has " << animal.num_legs << " legs and says " << animal.sound << '\n';
        }
    }
}

void userInput(std::array<Animal::Data, Animal::max_animals> &data)
{
    std::string user_animal{};

    std::cout << "Enter an animal: ";
    std::cin >> user_animal;

    printData(data, user_animal);
}

int main()
{
    userInput(Animal::animal_data);

    return 0;
}
