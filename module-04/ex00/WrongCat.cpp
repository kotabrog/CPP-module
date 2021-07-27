#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& a)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = a;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& a)
{
    type = a.getType();
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "makeSound: nyaaaaaaaaaa!!" << std::endl;
}
