#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdlib>

class Cat : public Animal
{
private:
    Brain* brain;

public:
    Cat();
    Cat(const Cat& a);
    virtual ~Cat();

    Cat& operator=(const Cat& a);

    const std::string& getBrainIdeas(int index) const;
    void setBrainIdeas(int index, const std::string& str);

    virtual void makeSound() const;
};

#endif
