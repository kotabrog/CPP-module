#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria& a);
    virtual ~AMateria();

    virtual AMateria& operator=(const AMateria&);

    std::string const & getType() const;

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
