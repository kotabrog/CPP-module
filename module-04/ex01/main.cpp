#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* sample[4];

    for (int i = 0; i < 2; ++i)
    {
        sample[i] = new Dog();
    }
    for (int i = 2; i < 4; ++i)
    {
        sample[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i)
    {
        delete sample[i];
    }

    Cat cat;
    Cat cat2;
    cat.setBrainIdeas(0, "str");
    cat2 = cat;
    std::cout << "cat brain ideas 0: " << cat.getBrainIdeas(0) << std::endl;
    std::cout << "cat2 brain ideas 0: " << cat2.getBrainIdeas(0) << std::endl;
    std::cout << "cat brain ideas 0 addres: " << &(cat.getBrainIdeas(0)) << std::endl;
    std::cout << "cat2 brain ideas 0 addres: " << &(cat2.getBrainIdeas(0)) << std::endl;

    Cat cat3;
    cat3.setBrainIdeas(0, "str");
    Cat cat4(cat3);
    std::cout << "cat3 brain ideas 0: " << cat3.getBrainIdeas(0) << std::endl;
    std::cout << "cat4 brain ideas 0: " << cat4.getBrainIdeas(0) << std::endl;
    std::cout << "cat3 brain ideas 0 addres: " << &(cat3.getBrainIdeas(0)) << std::endl;
    std::cout << "cat4 brain ideas 0 addres: " << &(cat4.getBrainIdeas(0)) << std::endl;
}
