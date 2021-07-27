#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& a);
    virtual ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& a);

    const std::string& getType() const;

    void makeSound() const;
};

#endif
