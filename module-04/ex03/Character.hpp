#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define NUM_MATERIA 4

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* materia[NUM_MATERIA];
    bool checkIndex(int index) const;

public:
    Character();
    Character(const std::string& name);
    Character(const Character& a);
    virtual ~Character();

    Character& operator=(const Character& a);

    virtual std::string const & getName() const;
    const AMateria* getMateria(int index) const;

    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif
