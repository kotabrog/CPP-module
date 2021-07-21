#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

public:
    void set_contact(std::string first_name,
                     std::string last_name,
                     std::string nickname,
                     std::string phone_number,
                     std::string darkest_secret);
    void put_contact() const;
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    bool is_empty() const;
};

#endif
