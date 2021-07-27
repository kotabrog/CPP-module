#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& a)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = a;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& a)
{
    type = a.getType();
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "makeSound: one!!" << std::endl;
}
