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
};
