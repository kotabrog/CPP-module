#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
    try
    {
        brain = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        throw e;
    }
}

Cat::Cat(const Cat& a)
{
    std::cout << "Cat copy constructor called" << std::endl;
    try
    {
        brain = new Brain();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        throw e;
    }
    *this = a;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

Cat& Cat::operator=(const Cat& a)
{
    type = a.getType();
    *brain = *(a.brain);
    return *this;
}

const std::string& Cat::getBrainIdeas(int index) const
{
    return brain->getIdeas(index);
}

void Cat::setBrainIdeas(int index, const std::string& str)
{
    brain->setIdeas(index, str);
}

void Cat::makeSound() const
{
    std::cout << "makeSound: nyaaaaaaaaaa!!" << std::endl;
}
