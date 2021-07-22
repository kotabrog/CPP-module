#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
private:
    std::string name;

public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    std::string get_name() const;
    void set_name(std::string name);
    void announce(void) const;
};

#endif
