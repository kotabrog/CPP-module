#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *z;

    if (N < 0)
        return (NULL);

    try
    {
        z = new Zombie[N];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }

    while (N--)
    {
        z[N].set_name(name);
    }
    return z;
}
