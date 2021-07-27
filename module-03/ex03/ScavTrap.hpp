#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
protected:
    unsigned int hitpoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& a);
    virtual ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

#endif
