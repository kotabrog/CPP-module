#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

#define NUM_IDEAS 100

class Brain
{
private:
    std::string ideas[NUM_IDEAS];
    bool checkIndex(int index) const;

public:
    Brain();
    Brain(const Brain& a);
    ~Brain();

    Brain& operator=(const Brain& a);

    const std::string& getIdeas(int index) const;
    void setIdeas(int index, const std::string& str);
};

#endif
