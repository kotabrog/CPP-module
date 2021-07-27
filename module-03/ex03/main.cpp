#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap a;
    std::cout << "name: " << a.getName() << std::endl;
    std::cout << "pairent name: " << a.getPairentName() << std::endl;
    std::cout << "hitpoints: " << a.getHitpoints() << std::endl;
    std::cout << "energyPoints: " << a.getEnergyPoints() << std::endl;
    std::cout << "attackDamage: " << a.getAttackDamage() << std::endl;
    a.takeDamage(3);
    DiamondTrap b(a);
    b.takeDamage(3);
    DiamondTrap c;
    c = b;
    b.takeDamage(3);

    DiamondTrap d("crap");
    d.attack("tag");
    d.takeDamage(4);
    d.beRepaired(10);
    d.highFivesGuys();
    d.guardGate();
    d.whoAmI();
}
