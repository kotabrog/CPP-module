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
    std::cout << "ScavTrap destructor of " << getName() << " called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& a)
{
    name = a.getName();
    hitpoints = a.getHitpoints();
    energyPoints = a.getEnergyPoints();
    attackDamage = a.getAttackDamage();
    return *this;
}

unsigned int ScavTrap::getHitpoints(void) const
{
    return hitpoints;
}

unsigned int ScavTrap::getEnergyPoints(void) const
{
    return energyPoints;
}

unsigned int ScavTrap::getAttackDamage(void) const
{
    return attackDamage;
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << getName() << \
                 " attacks " << target << \
                 ", causing " << attackDamage << \
                 " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    hitpoints = (hitpoints < amount) ? 0 : hitpoints - amount;
    std::cout << "ScavTrap " << getName() << \
                 " took " << amount << \
                 " damage, hit points to " << hitpoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    hitpoints += amount;
    std::cout << "ScavTrap " << getName() << \
                 " is repaired " << amount << \
                 ", hit points to " << hitpoints << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode" << std::endl;
}
