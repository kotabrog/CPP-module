#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& a)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = a;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& a)
{
    for (int i = 0; i < NUM_IDEAS; ++i)
    {
        this->setIdeas(i, a.getIdeas(i));
    }
    return *this;
}

bool Brain::checkIndex(int index) const
{
    if (index < 0 || index >= NUM_IDEAS)
    {
        std::cerr << "The value of index is out of range." << std::endl;
        return false;
    }
    return true;
}

const std::string& Brain::getIdeas(int index) const
{
    if (checkIndex(index))
    {
        return ideas[index];
    }
    return ideas[0];
}

void Brain::setIdeas(int index, const std::string& str)
{
    if (checkIndex(index))
    {
        ideas[index] = str;
    }
}
