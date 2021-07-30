#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

#define NUM_MATERIA_SOURCE 4

class MateriaSource : public IMateriaSource
{
    AMateria* materia[NUM_MATERIA_SOURCE];
    bool checkIndex(int index) const;

public:
    MateriaSource();
    MateriaSource(const MateriaSource& a);
    virtual ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& a);

    const AMateria* getMateria(int index) const;

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
