#include "Karen.hpp"

int main(int argc, char *argv[])
{
    Karen karen;

    if (argc != 2)
    {
        std::cerr << "One argument is required" << std::endl;
        std::exit(1);
    }
    std::string str = argv[1];

    std::string level_list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int level = Level::other;
    for (int i = 0; i < 4; ++i)
    {
        if (str == level_list[i])
        {
            level = i;
            break;
        }
    }
    switch (level)
    {
        case Level::debug:
            std::cout << "[ DEBUG ]\n";
            karen.complain("DEBUG");
            std::cout << std::endl;
        case Level::info:
            std::cout << "[ INFO ]\n";
            karen.complain("INFO");
            std::cout << std::endl;
        case Level::warning:
            std::cout << "[ WARNING ]\n";
            karen.complain("WARNING");
            std::cout << std::endl;
        case Level::error:
            std::cout << "[ ERROR ]\n";
            karen.complain("ERROR");
            std::cout << std::endl;
            break;
        case Level::other:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
