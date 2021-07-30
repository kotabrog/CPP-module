#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const & type) : AMateria(type) {}

Cure::Cure(const Cure& a)
{
    *this = a;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure&)
{
    type = "cure";
    return *this;
}

AMateria* Cure::clone() const
{
    try
    {
        AMateria* a = new Cure;
        return a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << \
                 "'s wounds *" << std::endl;
}
