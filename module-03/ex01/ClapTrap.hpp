#ifndef CRAPTRAP_H
#define CRAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string name;
    unsigned int hitpoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& a);
    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& a);

    const std::string& getName(void) const;
    unsigned int getHitpoints(void) const;
    unsigned int getEnergyPoints(void) const;
    unsigned int getAttackDamage(void) const;

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
