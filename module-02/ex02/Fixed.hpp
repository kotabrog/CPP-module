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

    bool operator==(const Fixed& a) const;
    bool operator!=(const Fixed& a) const;
    bool operator<(const Fixed& a) const;
    bool operator>(const Fixed& a) const;
    bool operator<=(const Fixed& a) const;
    bool operator>=(const Fixed& a) const;

    Fixed operator+(const Fixed& a) const;
    Fixed operator-(const Fixed& a) const;
    Fixed operator*(const Fixed& a) const;
    Fixed operator/(const Fixed& a) const;

    Fixed operator+() const;
    Fixed operator-() const;

    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    int getRawBits(void) const;
    void setRawBits(const int raw);

    float toFloat(void) const;
    int toInt(void) const;

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed &a);

#endif
