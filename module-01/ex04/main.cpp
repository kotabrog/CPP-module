#include <iostream>
#include <string>
#include <fstream>

void error_put(std::string error_message)
{
    std::cerr << error_message << std::endl;
    std::exit(1);
}

void file_to_string(const std::string& file_name, std::string& dst)
{
    std::ifstream ifs(file_name);
    if (!ifs)
    {
        error_put("Failed to open");
    }

    char c;
    while (ifs.get(c))
    {
        dst += c;
    }
    if (!ifs.eof())
    {
        error_put("Failed to read");
    }
}

void string_to_file(const std::string& file_name, const std::string& str)
{
    std::ofstream ofs(file_name);
    if (!ofs)
    {
        error_put("Failed to open");
    }
    ofs << str;
    if (ofs.fail())
    {
        error_put("Failed to write");
    }
}

std::string replace_string(const std::string s1,
                           const std::string s2,
                           const std::string& str)
{
    std::size_t s1_size = s1.length();
    std::string dst;

    std::string::size_type before_pos = 0;
    std::string::size_type pos = str.find(s1);
    while (pos != std::string::npos)
    {
        dst += str.substr(before_pos, pos - before_pos);
        dst += s2;
        before_pos = pos + s1_size;
        pos = str.find(s1, before_pos);
    }
    dst += str.substr(before_pos);
    return dst;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        error_put("Three arguments are required");
    }
    if (argv[2][0] == '\0' || argv[3][0] == '\0')
    {
        error_put("String is empty");
    }

    std::string file_name = argv[1];
    std::string str;
    file_to_string(file_name, str);
    file_name += ".replace";
    str = replace_string(argv[2], argv[3], str);
    string_to_file(file_name, str);
}
