#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& a);
    virtual ~Dog();

    Dog& operator=(const Dog& a);

    virtual void makeSound() const;
};

#endif
