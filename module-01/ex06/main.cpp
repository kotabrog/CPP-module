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

    std::string level_list[LEVEL_NUM] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int level = LEVEL_NUM;
    for (int i = 0; i < LEVEL_NUM; ++i)
    {
        if (str == level_list[i])
        {
            level = i;
            break;
        }
    }
    switch (level)
    {
        case DEBUG:
            std::cout << "[ DEBUG ]\n";
            karen.complain("DEBUG");
            std::cout << std::endl;
        case INFO:
            std::cout << "[ INFO ]\n";
            karen.complain("INFO");
            std::cout << std::endl;
        case WARNING:
            std::cout << "[ WARNING ]\n";
            karen.complain("WARNING");
            std::cout << std::endl;
        case ERROR:
            std::cout << "[ ERROR ]\n";
            karen.complain("ERROR");
            std::cout << std::endl;
            break;
        case LEVEL_NUM:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
