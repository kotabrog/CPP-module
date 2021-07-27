#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& a);
    ~FragTrap();

    virtual void attack(const std::string& target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
    void highFivesGuys(void);
};

#endif
