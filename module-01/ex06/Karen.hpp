#ifndef KAREN_H
#define KAREN_H

#include <iostream>
#include <string>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3
#define LEVEL_NUM 4


class Karen
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    void complain( std::string level );
};

#endif