#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
    Zombie *z;
    std::string s;
    int n;

    n = 5;
    s = "zombie2";
    z = zombieHorde(n, s);
    for (int i = 0; i < n; ++i)
    {
        z[i].announce();
    }
    delete[] z;
}
