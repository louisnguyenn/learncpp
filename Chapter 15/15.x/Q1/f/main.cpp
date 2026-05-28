#include <iostream>
#include <string>
#include <string_view>

class Monster
{
  public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes
    };

  private:
    Type m_type{};
    std::string m_name;
    std::string m_roar;
    int m_hitPoints{};

    // constructor
  public:
    Monster(Type type, std::string_view name, std::string_view roar, int hitPoints)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {
    }

    std::string_view getTypeString()
    {
        switch (m_type)
        {
        case Type::dragon:
            return "dragon";
        case Type::goblin:
            return "goblin";
        case Type::ogre:
            return "orge";
        case Type::orc:
            return "orc";
        case Type::skeleton:
            return "skeleton";
        case Type::troll:
            return "troll";
        case Type::vampire:
            return "vampire";
        case Type::zombie:
            return "zombie";
        default:
            return "???";
        }
    }

    void print()
    {
        if (m_hitPoints > 0)
        {
            std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << '\n';
        }
        else
        {
            std::cout << m_name << " the " << getTypeString() << " is dead.\n";
        }
    }
};

namespace MonsterGenerator
{
    Monster generate()
    {
        return Monster{Monster::skeleton, "Bones", "*rattle*", 4};
    }
};

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
