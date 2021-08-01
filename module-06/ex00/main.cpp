#include <iostream>
#include <string>
#include <climits>

void put_exit_error(std::string str)
{
    std::cerr << str << std::endl;
    std::exit(1);
}

void put_int_to_char(int num)
{
    if (' ' <= num && num <= '~')
    {
        std::cout << "char: " << static_cast<char>(num) << std::endl;
    }
    else if (0 <= num && num <= 127)
    {
        std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }
}

void put_float_to_int_and_char(float num)
{
    if (num < INT_MIN || INT_MAX < num)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        put_int_to_char(static_cast<int>(num));
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    }
}

void put_double_to_int_and_char(double num)
{
    if (num < INT_MIN || INT_MAX < num)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        put_int_to_char(static_cast<int>(num));
        std::cout << "int: " << static_cast<int>(num) << std::endl;
    }
}

// bool is_decimal_zero(std::string str)
// {

// }

// int check_numeric_and_exit(const std::string& str)
// {
//     bool dot_flag = false;
//     for (size_t i = 0; i < str.length(); ++i)
//     {
//         if (str[i] == '.')
//         {
//             if (dot_flag)
//                 put_exit_error(str + " can't convert.");
//             dot_flag = true;
//         }
//     }
// }

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Only one argument" << std::endl;
        return 0;
    }

    std::string str(argv[1]);

    int int_num = 0;
    bool int_flag = false;
    try
    {
        int_num = std::stoi(str);
        int_flag = true;
    }
    catch(const std::exception& e) {}

    double double_num = 0;
    bool double_flag = false;
    try
    {
        double_num = std::stod(str);
        double_flag = true;
    }
    catch(const std::exception& e) {}

    float float_num = 0;
    bool float_flag = false;
    try
    {
        float_num = std::stof(str);
        float_flag = true;
    }
    catch(const std::exception& e) {}

    if (!double_flag)
    {
        if (str.length() != 1)
        {
            std::cout << str << ": Can't convert." << std::endl;
            return 0;
        }
        char c = str[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return 0;
    }

    if (!int_flag)
    {
        if (str[str.length() - 1] == 'f')
        {
            if (!float_flag)
            {
                std::cout << str << ": Can't convert." << std::endl;
                return 0;
            }
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << float_num << std::endl;
            std::cout << "double: " << static_cast<double>(float_num) << std::endl;
            return 0;
        }
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (!float_flag)
        {
            std::cout << "float: impossible" << std::endl;
        }
        else
        {
            std::cout << "float: " << static_cast<float>(double_num) << std::endl;
        }
        std::cout << "double: " << double_num << std::endl;
        return 0;
    }

    if (static_cast<int>(double_num) != int_num || \
        str.find('.') != std::string::npos)
    {
        if (str[str.length() - 1] == 'f')
        {
            if (!float_flag)
            {
                std::cout << str << ": Can't convert." << std::endl;
                return 0;
            }
            put_float_to_int_and_char(float_num);
            std::cout << "float: " << float_num << std::endl;
            std::cout << "double: " << static_cast<double>(float_num) << std::endl;
            return 0;
        }
        put_double_to_int_and_char(double_num);
        if (!float_flag)
        {
            std::cout << "float: impossible" << std::endl;
        }
        else
        {
            std::cout << "float: " << static_cast<float>(double_num) << std::endl;
        }
        std::cout << "double: " << double_num << std::endl;
        return 0;
    }
    put_int_to_char(int_num);
    std::cout << "int: " << int_num << std::endl;
    std::cout << "float: " << static_cast<float>(int_num) << std::endl;
    std::cout << "double: " << static_cast<double>(int_num) << std::endl;
}
