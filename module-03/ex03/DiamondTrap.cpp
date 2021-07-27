#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("no name_clap_name"), name("no name")
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), name(name)
{
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& a)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = a;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor of " << name << " called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& a)
{
    name = a.getName();
    this->ClapTrap::name = a.getPairentName();
    hitpoints = a.getHitpoints();
    energyPoints = a.getEnergyPoints();
    attackDamage = a.getAttackDamage();
    return *this;
}

const std::string& DiamondTrap::getName(void) const
{
    return name;
}

const std::string& DiamondTrap::getPairentName(void) const
{
    return this->ClapTrap::name;
}

unsigned int DiamondTrap::getHitpoints(void) const
{
    return this->FragTrap::hitpoints;
}

unsigned int DiamondTrap::getEnergyPoints(void) const
{
    return this->ScavTrap::energyPoints;
}

unsigned int DiamondTrap::getAttackDamage(void) const
{
    return this->FragTrap::attackDamage;
}

// void DiamondTrap::attack(const std::string& target)
// {
//     this->ScavTrap::attack(target);
// }

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << name << \
                 ", my pairent name is " << this->getPairentName() << std::endl;
}
