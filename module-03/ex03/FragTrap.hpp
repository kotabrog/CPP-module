#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
protected:
    unsigned int hitpoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& a);
    virtual ~FragTrap();

    unsigned int getHitpoints(void) const;
    unsigned int getEnergyPoints(void) const;
    unsigned int getAttackDamage(void) const;

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void highFivesGuys(void);
};

#endif
