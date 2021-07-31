#include "RobotomyRequestForm.hpp"

bool RobotomyRequestForm::action() const
{
    std::srand(std::clock());
    if (rand() % 2)
    {
        std::cout << "buzz-buzz... " << getTarget() << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "buzz-buzz... " << getTarget() << " has failed to make robotomized." << std::endl;
    }
    return true;
}

RobotomyRequestForm::RobotomyRequestForm()
    : Form("RobotomyRequest", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : Form("RobotomyRequest", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& a)
    : Form(a) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&)
{
    return *this;
}
