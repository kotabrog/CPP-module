#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *z;

    try
    {
        z = new Zombie(name);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    return z;
}
