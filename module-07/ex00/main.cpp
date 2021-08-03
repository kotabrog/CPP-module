#include <iostream>
#include "whatever.hpp"

int main()
{
    {
        int a = 1;
        int b = 2;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        swap(a, b);
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        double a = 1;
        double b = 2;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        swap(a, b);
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        int a = 1;
        int b = 2;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "a ptr: " << &a << ", b ptr: " << &b << std::endl;
        std::cout << "min: " << min(a, b) << std::endl;
        std::cout << "min ptr: " << &min(a, b) << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        double a = 1;
        double b = 1;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "a ptr: " << &a << ", b ptr: " << &b << std::endl;
        std::cout << "min: " << min(a, b) << std::endl;
        std::cout << "min ptr: " << &min(a, b) << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        int a = 1;
        int b = 2;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "a ptr: " << &a << ", b ptr: " << &b << std::endl;
        std::cout << "max: " << max(a, b) << std::endl;
        std::cout << "max ptr: " << &max(a, b) << std::endl;
    }
    std::cout << "------" << std::endl;
    {
        double a = 1;
        double b = 1;
        std::cout << "a: " << a << ", b: " << b << std::endl;
        std::cout << "a ptr: " << &a << ", b ptr: " << &b << std::endl;
        std::cout << "max: " << max(a, b) << std::endl;
        std::cout << "max ptr: " << &max(a, b) << std::endl;
    }
}