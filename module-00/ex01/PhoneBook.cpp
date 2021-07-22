#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : add_index(0) {}

void PhoneBook::put_one(std::string str) const
{
    size_t str_len;

    str_len = str.length();
    if (str_len <= 10)
    {
        std::cout << std::setw(10) << std::right << str;
    }
    else
    {
        std::cout << str.substr(0, 9) << ".";
    }
}

void PhoneBook::put_contact_list() const
{
    int i;

    i = 0;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    while (i < CONTACT_NUM && !cot[i].is_empty())
    {
        std::cout << std::setw(10) << std::right << i << "|";
        put_one(cot[i].get_first_name());
        std::cout << "|";
        put_one(cot[i].get_last_name());
        std::cout << "|";
        put_one(cot[i].get_nickname());
        std::cout << "\n" << std::endl;
        ++i;
    }
}

std::string PhoneBook::input_one(std::string put_string) const
{
    std::string str;

    while (str.empty())
    {
        std::cout << put_string << std::endl;
        std::getline(std::cin, str);
    }
    return str;
}

void PhoneBook::add_command()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter new contact information" << std::endl;
    first_name = input_one("Enter first name");
    last_name = input_one("Enter last name");
    nickname = input_one("Enter nickname");
    phone_number = input_one("Enter phone number");
    darkest_secret = input_one("Enter darkest secret");
    cot[add_index].set_contact(first_name,
                               last_name,
                               nickname,
                               phone_number,
                               darkest_secret);
    add_index = (add_index + 1) % CONTACT_NUM;
    std::cout << "Registration is complete\n" << std::endl;
}

void PhoneBook::search_command() const
{
    if (cot[0].is_empty())
    {
        std::cout << "There are no contacts to display\n" << std::endl;
        return ;
    }

    put_contact_list();

    while (true)
    {
        std::string str;

        std::cout << "Enter an index" << std::endl;
        std::getline(std::cin, str);
        if (str.length() == 1 && \
            '0' <= str[0] && str[0] <= '7' && \
            !cot[str[0] - '0'].is_empty())
        {
            cot[str[0] - '0'].put_contact();
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid input" << std::endl;
        }
    }
}

void PhoneBook::loop()
{
    std::cout << "ADD: Add a contact" << std::endl;
    std::cout << "SEARCH: Display a contact" << std::endl;
    std::cout << "EXIT: Exit the program\n" << std::endl;
    while (true)
    {
        std::string command;

        std::cout << "Enter the command" << std::endl;
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            add_command();
        }
        else if (command == "SEARCH")
        {
            search_command();
        }
        else if (command == "EXIT")
        {
            break;
        }
    }
}
