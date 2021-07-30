#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria(const AMateria& a)
{
    *this = a;
}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria&)
{
    type = "";
    return *this;
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "There was nothing "<< target.getName() << \
                 " could do." << std::endl;
}
