#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal& a);
    virtual ~Animal();

    Animal& operator=(const Animal& a);

    const std::string& getType() const;

    virtual void makeSound() const = 0;
};

#endif
