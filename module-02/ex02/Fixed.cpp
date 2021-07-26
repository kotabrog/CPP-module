#include "Fixed.hpp"

Fixed::Fixed() : raw(0) {}

Fixed::Fixed(int value)
{
    raw = static_cast<int>(std::roundf(value * (1 << point)));
}

Fixed::Fixed(float value)
{
    raw = static_cast<int>(std::roundf(value * (1 << point)));
}

Fixed::Fixed(const Fixed& a)
{
    *this = a;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& a)
{
    raw = a.getRawBits();
    return *this;
}

bool Fixed::operator==(const Fixed& a) const
{
    return (raw == a.getRawBits());
}

bool Fixed::operator!=(const Fixed& a) const
{
    return !(*this == a);
}

bool Fixed::operator<(const Fixed& a) const
{
    return raw < a.getRawBits();
}

bool Fixed::operator>(const Fixed& a) const
{
    return a < *this;
}

bool Fixed::operator<=(const Fixed& a) const
{
    return !(a < *this);
}

bool Fixed::operator>=(const Fixed& a) const
{
    return a <= *this;
}

Fixed Fixed::operator+(const Fixed& a) const
{
    Fixed ret;
    ret.setRawBits(raw + a.getRawBits());
    return ret;
}

Fixed Fixed::operator-(const Fixed& a) const
{
    Fixed ret;
    ret.setRawBits(raw - a.getRawBits());
    return ret;
}

Fixed Fixed::operator*(const Fixed& a) const
{
    Fixed ret;
    long new_raw = raw;
    new_raw *= a.getRawBits();
    new_raw >>= point;
    ret.setRawBits(static_cast<int>(new_raw));
    return ret;
}

Fixed Fixed::operator/(const Fixed& a) const
{
    Fixed ret;
    long new_raw = raw;
    new_raw <<= point;
    if (a.getRawBits() == 0)
    {
        std::cerr << "division by zero is undefined" << std::endl;
        std::exit(1);
    }
    new_raw /= a.getRawBits();
    ret.setRawBits(static_cast<int>(new_raw));
    return ret;
}

Fixed Fixed::operator+() const
{
    return *this;
}

Fixed Fixed::operator-() const
{
    Fixed ret;
    ret.setRawBits(-raw);
    return ret;
}

Fixed& Fixed::operator++()
{
    ++raw;
    return *this;
}

Fixed& Fixed::operator--()
{
    --raw;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed ret(*this);
    ++*this;
    return ret;
}

Fixed Fixed::operator--(int)
{
    Fixed ret(*this);
    --*this;
    return ret;
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a <= b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a <= b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a >= b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a >= b ? a : b);
}

std::ostream& operator<<(std::ostream& os, const Fixed &a)
{
    os << a.toFloat();
    return os;
}
