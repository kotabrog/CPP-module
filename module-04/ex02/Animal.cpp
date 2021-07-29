#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& a)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
    type = a.getType();
    return *this;
}

const std::string& Animal::getType() const
{
    return type;
}
