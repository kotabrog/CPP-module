#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
    try
    {
        brain = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }
}

Dog::Dog(const Dog& a)
{
    std::cout << "Dog copy constructor called" << std::endl;
    try
    {
        brain = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::exit(1);
    }
    *this = a;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog& Dog::operator=(const Dog& a)
{
    type = a.getType();
    *brain = *(a.brain);
    return *this;
}

const std::string& Dog::getBrainIdeas(int index) const
{
    return brain->getIdeas(index);
}

void Dog::setBrainIdeas(int index, const std::string& str)
{
    brain->setIdeas(index, str);
}

void Dog::makeSound() const
{
    std::cout << "makeSound: one!!" << std::endl;
}
