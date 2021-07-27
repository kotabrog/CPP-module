#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    hitpoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->name = name;
    hitpoints = 100;
    energyPoints = 100;
    attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& a)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = a;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor of " << name << " called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    std::cout << "FragTrap " << name << \
                 " attacks " << target << \
                 ", causing " << attackDamage << \
                 " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " said. Give me a high five! Please!" << std::endl;
}
