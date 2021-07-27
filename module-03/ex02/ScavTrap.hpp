#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& a);
    ~ScavTrap();

    virtual void attack(const std::string& target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
    void guardGate();
};

#endif
