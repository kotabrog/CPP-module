#include "ClapTrap.hpp"

int main()
{
    ClapTrap a;
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
