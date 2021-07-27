#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& a)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = a;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& a)
{
    type = a.getType();
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "makeSound: nyaaaaaaaaaa!!" << std::endl;
}
