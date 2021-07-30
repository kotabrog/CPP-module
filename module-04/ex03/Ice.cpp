#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string const & type) : AMateria(type) {}

Ice::Ice(const Ice& a)
{
    *this = a;
}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice&)
{
    type = "ice";
    return *this;
}

AMateria* Ice::clone() const
{
    try
    {
        AMateria* a = new Ice;
        return a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 0;
    }
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << \
                 " *" << std::endl;
}
