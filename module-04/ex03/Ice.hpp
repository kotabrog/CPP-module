#ifndef ICE_H
#define ICE_H

#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
protected:
    std::string type;

public:
    Ice();
    Ice(std::string const & type);
    Ice(const Ice& a);
    virtual ~Ice();

    virtual Ice& operator=(const Ice&);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
