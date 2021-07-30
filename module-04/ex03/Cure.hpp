#ifndef CURE_H
#define CURE_H

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
protected:
    std::string type;

public:
    Cure();
    Cure(std::string const & type);
    Cure(const Cure& a);
    virtual ~Cure();

    virtual Cure& operator=(const Cure&);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
