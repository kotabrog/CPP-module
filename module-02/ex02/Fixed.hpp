#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <climits>

class Fixed
{
private:
    static const int point = 8;
    int raw;
    void intToRaw(int value);
    void fractionToRaw(float value);
    int rawToInt(void) const;
    float rawToFraction(void) const;

public:
    Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed& a);
    ~Fixed();

    Fixed& operator=(const Fixed& a);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &a);

#endif
