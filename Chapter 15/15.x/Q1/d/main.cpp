#include <string>

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
    Monster(Type type, std::string name, std::string roar, int hitPoints)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hitPoints{hitPoints}
    {
    }
};

int main()
{
    Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};

    return 0;
}