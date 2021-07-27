#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("no name"), hitpoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& a)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = a;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitpoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor of " << name << " called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& a)
{
    name = a.getName();
    hitpoints = a.getHitpoints();
    energyPoints = a.getEnergyPoints();
    attackDamage = a.getAttackDamage();
    return *this;
}

const std::string& ClapTrap::getName(void) const
{
    return name;
}

unsigned int ClapTrap::getHitpoints(void) const
{
    return hitpoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
    return energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
    return attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << name << \
                 " attacks " << target << \
                 ", causing " << attackDamage << \
                 " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitpoints = (hitpoints < amount) ? 0 : hitpoints - amount;
    std::cout << "ClapTrap " << name << \
                 " took " << amount << \
                 " damage, hit points to " << hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    hitpoints += amount;
    std::cout << "ClapTrap " << name << \
                 " is repaired " << amount << \
                 ", hit points to " << hitpoints << std::endl;
}
