#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include "contact.hpp"

#define CONTACT_NUM 8

class PhoneBook
{
private:
    contact cot[8];
    int add_index;

    void put_one(std::string str) const;
    void put_contact_list() const;
    std::string input_one(std::string put_string) const;
    void add_command();
    void search_command() const;

public:
    PhoneBook();
    void loop();
};

#endif
