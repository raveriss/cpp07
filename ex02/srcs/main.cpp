
/* inclussion of Array.hpp is necessary to use the Array class */
#include "../incs/Array.hpp"

/* inclussion of iostream is necessary for std::cout and std::cerr */
#include <iostream>

/**
 * @brief Main function
*/
int main()
{
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
    {
        a[i] = i;
    }

    for (unsigned int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    try
    {
        std::cout << a[5] << std::endl; // Should throw an exception
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    Array<int> b(a);
    b[0] = 42;

    for (unsigned int i = 0; i < b.size(); ++i)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    for (unsigned int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

/* main.cpp */