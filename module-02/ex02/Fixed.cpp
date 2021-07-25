#include "Fixed.hpp"

void Fixed::intToRaw(int value)
{
    int bit_size = sizeof(int) * 8;
    int fixed_int_bit_size = bit_size - point;

    if (point == 0)
    {
        raw = value;
        return ;
    }
    if (fixed_int_bit_size == 1)
    {
        raw = (value < 0) ? INT_MIN : 0;
        return ;
    }
    if (value < 0)
    {
        int fixed_int_min = 1;
        fixed_int_min <<= fixed_int_bit_size - 1;
        fixed_int_min *= -1;
        if (value <= fixed_int_min)
        {
            raw = INT_MIN;
            return ;
        }
        value <<= point + 1;
        value >>= 1;
        value |= INT_MIN;
        raw = value;
        return ;
    }
    value <<= point + 1;
    value >>= 1;
    value &= INT_MAX;
    raw = value;
}

void Fixed::fractionToRaw(float value)
{
    float epsilon = 1e-7;
    int fraction = 0;
    float check_num = 1;
    for (int i = 0; i < point - 1; ++i)
    {
        check_num /= 2;
        if (value > check_num - epsilon)
        {
            int bit_one = 1;
            bit_one <<= point - i - 1;
            fraction |= bit_one;
            value -= check_num;
        }
    }
    if (check_num / 4 < value)
    {
        fraction |= 1;
    }
    raw |= fraction;
}

int Fixed::rawToInt(void) const
{
    int bit_size = sizeof(int) * 8;
    int fixed_int_bit_size = bit_size - point;

    if (point == 0)
    {
        return raw;
    }
    if (fixed_int_bit_size == 1)
    {
        return 0;
    }
    if (raw < 0)
    {
        int value = raw & INT_MAX;
        if (value == 0)
        {
            int fixed_int_min = 1;
            fixed_int_min <<= fixed_int_bit_size - 1;
            fixed_int_min *= -1;
            return fixed_int_min;
        }
        int mask = -1;
        mask <<= fixed_int_bit_size - 1;
        value >>= point;
        value |= mask;
        return value;
    }
    return raw >> point;
}

float Fixed::rawToFraction(void) const
{
    float value = 0;
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

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value)
{
    std::cout << "Int constructor called" << std::endl;
    intToRaw(value);
}

Fixed::Fixed(float value)
{
    std::cout << "Float constructor called" << std::endl;
    intToRaw(static_cast<int>(value));
    if (value < 0)
    {
        value *= -1;
    }
    value -= static_cast<int>(value);
    fractionToRaw(value);
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
    return rawToInt();
}

float Fixed::toFloat(void) const
{
    float value = rawToInt();
    int sign = (value >= 0) ? 1 : -1;
    value += sign * rawToFraction();
    return value;
}

std::ostream& operator<<(std::ostream& os, const Fixed &a)
{
    os << a.toFloat();
    return os;
}
