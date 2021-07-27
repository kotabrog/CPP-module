#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = name;
    hitpoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& a)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = a;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor of " << name << " called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << name << \
                 " attacks " << target << \
                 ", causing " << attackDamage << \
                 " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}
