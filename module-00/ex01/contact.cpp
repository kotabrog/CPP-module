#include "contact.hpp"

void contact::set_contact(std::string first_name,
                          std::string last_name,
                          std::string nickname,
                          std::string phone_number,
                          std::string darkest_secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nickname = nickname;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

void contact::put_contact() const
{
    std::cout << "first name: " << this->first_name << std::endl;
    std::cout << "last name: " << this->last_name << std::endl;
    std::cout << "nickname: " << this->nickname << std::endl;
    std::cout << "phone number: " << this->phone_number << std::endl;
    std::cout << "darkest secret: " << this->darkest_secret << std::endl;
}

std::string contact::get_first_name() const
{
    return this->first_name;
}

std::string contact::get_last_name() const
{
    return this->last_name;
}

std::string contact::get_nickname() const
{
    return this->nickname;
}

bool contact::is_empty() const
{
    return (this->first_name.empty());
}
