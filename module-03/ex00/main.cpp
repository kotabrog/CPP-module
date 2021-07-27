#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
    std::cout << "hitpoints: " << a.getHitpoints() << std::endl;
    std::cout << "energyPoints: " << a.getEnergyPoints() << std::endl;
    std::cout << "attackDamage: " << a.getAttackDamage() << std::endl;
    a.takeDamage(3);
    ClapTrap b(a);
    b.takeDamage(3);
    ClapTrap c;
    c = b;
    b.takeDamage(3);

    ClapTrap d("crap");
    d.attack("tag");
    d.takeDamage(4);
    d.beRepaired(10);
}
