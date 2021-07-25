#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (weapon)
    {
        std::cout << name << " attacks with his " << weapon->getType() << std::endl;
    }
}
