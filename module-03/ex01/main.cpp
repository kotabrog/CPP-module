#include "ScavTrap.hpp"

int main()
{
    ScavTrap a;
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
