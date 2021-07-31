#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        PresidentialPardonForm pre("tag");
        Bureaucrat bru("bru", 1);

        bru.signForm(pre);
        bru.executeForm(pre);
        std::cout << bru << std::endl;
        std::cout << pre << std::endl;
    }

    std::cout << "------------" << std::endl;

    {
        PresidentialPardonForm pre("tag");
        Bureaucrat bru("bru", 10);

        bru.signForm(pre);
        bru.executeForm(pre);
        std::cout << bru << std::endl;
        std::cout << pre << std::endl;
    }

    std::cout << "------------" << std::endl;

    {
        PresidentialPardonForm pre("tag");
        Bureaucrat bru("bru", 1);

        pre.beSigned(bru);
        pre.execute(bru);
        std::cout << bru << std::endl;
        std::cout << pre << std::endl;
    }

    std::cout << "------------" << std::endl;

    {
        PresidentialPardonForm pre("tag");
        Bureaucrat bru("bru", 1);

        bru.executeForm(pre);
        std::cout << bru << std::endl;
        std::cout << pre << std::endl;
    }
}
