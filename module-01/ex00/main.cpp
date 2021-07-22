#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main()
{
    Zombie *z;
    std::string s;

    s = "zombie";
    z = newZombie(s);
    z->announce();
    s = "zombie2";
    randomChump(s);
    delete z;
}
