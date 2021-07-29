#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdlib>

class Dog : public Animal
{
private:
    Brain* brain;

public:
    Dog();
    Dog(const Dog& a);
    virtual ~Dog();

    Dog& operator=(const Dog& a);

    const std::string& getBrainIdeas(int index) const;
    void setBrainIdeas(int index, const std::string& str);

    virtual void makeSound() const;
};

#endif
