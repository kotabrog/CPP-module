#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
    std::cout << "Int constructor called" << std::endl;
    raw = static_cast<int>(std::roundf(value * (1 << point)));
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called" << std::endl;
    raw = static_cast<int>(std::roundf(value * (1 << point)));
}

Fixed::Fixed(const Fixed& a)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& a)
{
    std::cout << "Assignation operator called" << std::endl;
    raw = a.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return raw;
}

void Fixed::setRawBits(const int raw)
{
    this->raw = raw;
}

int Fixed::toInt(void) const
{
    int value = raw;
    value >>= point;
    return value;
}

float Fixed::toFloat(void) const
{
    int value_int = raw;
    value_int >>= point;
    float value = value_int;
    float value_to_add = 1;
    for (int i = 0; i < point; ++i)
    {
        value_to_add /= 2;
        int mask = 1;
        mask <<= point - i - 1;
        if (mask & raw)
        {
            value += value_to_add;
        }
    }
    return value;
}

std::ostream& operator<<(std::ostream& os, const Fixed &a)
{
    os << a.toFloat();
    return os;
}
