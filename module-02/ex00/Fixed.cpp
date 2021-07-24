#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed& Fixed::operator=(const Fixed& a)
{
    std::cout << "Assignation operator called" << std::endl;
    raw = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return raw;
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->raw = raw;
}
