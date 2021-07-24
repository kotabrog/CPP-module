#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
    static const int point = 8;
    int raw;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& a);
    Fixed& operator=(const Fixed& a);
    int getRawBits(void) const;
    void setRawBits(const int raw);
};

#endif
