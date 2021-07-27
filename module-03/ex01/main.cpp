#include "ScavTrap.hpp"

int main()
{
    ScavTrap a;
    std::cout << "hitpoints: " << a.getHitpoints() << std::endl;
    std::cout << "energyPoints: " << a.getEnergyPoints() << std::endl;
    std::cout << "attackDamage: " << a.getAttackDamage() << std::endl;
    a.takeDamage(3);
    ScavTrap b(a);
    b.takeDamage(3);
    ScavTrap c;
    c = b;
    b.takeDamage(3);

    ScavTrap d("crap");
    d.attack("tag");
    d.takeDamage(4);
    d.beRepaired(10);
    d.guardGate();
}
