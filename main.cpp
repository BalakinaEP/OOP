#include <iostream>
#include "Complex.h"


int main()
{
    Complex a(3, -1);
    Complex b(-3, -11);
    Complex c = a + b;

    std::cout << c << std::endl;
    c = a - b;
    std::cout << c << std::endl;
    c = 3 * a;
    std::cout << c << std::endl;
    c = a * b;
    std::cout << c << std::endl;
    c = a / 2.1;
    std::cout << c << std::endl;
    c = a / b;
    std::cout << c << std::endl;
    return 0;
}

