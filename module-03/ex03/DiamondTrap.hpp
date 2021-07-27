#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string name;
    using FragTrap::hitpoints;
    using ScavTrap::energyPoints;
    using FragTrap::attackDamage;

public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& a);
    virtual ~DiamondTrap();

    DiamondTrap& operator=(const DiamondTrap& a);

    const std::string& getName(void) const;
    const std::string& getPairentName(void) const;
    unsigned int getHitpoints(void) const;
    unsigned int getEnergyPoints(void) const;
    unsigned int getAttackDamage(void) const;

    using ScavTrap::attack;
    void whoAmI();
};

#endif
