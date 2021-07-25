#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <climits>
#include <cmath>

class Fixed
{
private:
    static const int point = 8;
    int raw;

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
