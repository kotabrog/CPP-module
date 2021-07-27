#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat& a);
    virtual ~WrongCat();

    WrongCat& operator=(const WrongCat& a);

    void makeSound() const;
};

#endif
