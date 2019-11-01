// Clang: clang++ -std=c++17 fibonacci.cpp
// GCC:   g++ -std=c++17 fibonacci.cpp
// MSVC:  cl /std:c++17 /EHsc fibonacci.cpp

#include <iostream>
#include "fibonacci.hpp"

int main()
{
    for (auto i : fibonacci()) {
        if (i > 10000) {
            break;
        }
        std::cout << i << std::endl;
    }
    int count = 0;
    for (auto i : fibonacci()) {
        std::cout << i << std::endl;
        if (++count == 20) {
            break;
        }
    }
}
