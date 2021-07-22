#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "str addres: " << &str << std::endl;
    std::cout << "stringPTR addres: " << stringPTR << std::endl;
    std::cout << "stringREF addres: " << &stringREF << std::endl;

    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
}
