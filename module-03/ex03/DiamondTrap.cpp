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

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << name << \
                 ", my pairent name is " << this->getPairentName() << std::endl;
}
