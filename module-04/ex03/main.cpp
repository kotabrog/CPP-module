#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "---------------------" << std::endl;
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());

    ICharacter* me2 = new Character("me2");
    tmp = src2->createMateria("ice");
    me2->equip(tmp);
    tmp = src2->createMateria("a");
    if (!tmp)
        std::cout << "NULL" << std::endl;
    tmp = src2->createMateria("cure");
    me2->equip(tmp);
    tmp = src2->createMateria("cure");
    me2->equip(tmp);
    tmp = src2->createMateria("cure");
    me2->equip(tmp);
    AMateria* tmp2 = src2->createMateria("cure");
    me2->equip(tmp2);
    delete tmp2;
    me2->unequip(3);
    delete tmp;
    me2->use(3, *me2);
    me2->use(2, *me2);
    me2->use(5, *me2);
    delete me2;
    delete src2;
}
