#include "Character.hpp"

bool Character::checkIndex(int index) const
{
    return (0 <= index && index < NUM_MATERIA);
}

Character::Character() : name("no name")
{
    for (int i = 0; i < NUM_MATERIA; ++i)
        materia[i] = NULL;
}

Character::Character(const std::string& name) : name(name)
{
    for (int i = 0; i < NUM_MATERIA; ++i)
        materia[i] = NULL;
}

Character::Character(const Character& a)
{
    *this = a;
}

Character::~Character()
{
    for (int i = 0; i < NUM_MATERIA; ++i)
    {
        if (materia[i])
        {
            delete materia[i];
        }
    }
}

Character& Character::operator=(const Character& a)
{
    name = a.getName();
    for (int i = 0; i < NUM_MATERIA; ++i)
    {
        const AMateria* tmp = a.getMateria(i);
        if (tmp)
        {
            materia[i] = tmp->clone();
        }
        else
        {
            materia[i] = NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return name;
}

const AMateria* Character::getMateria(int index) const
{
    if (!checkIndex(index))
    {
        return NULL;
    }
    return materia[index];
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < NUM_MATERIA; ++i)
    {
        if (!materia[i])
        {
            materia[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (!checkIndex(idx) || !materia[idx])
    {
        return ;
    }
    materia[idx] = NULL;
    for (int i = idx + 1; i < NUM_MATERIA; ++i)
    {
        if (!materia[i])
        {
            break;
        }
        materia[i - 1] = materia[i];
        materia[i] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (!checkIndex(idx) || !materia[idx])
    {
        return ;
    }
    materia[idx]->use(target);
}
