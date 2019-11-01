// Clang: clang++ -std=c++17 -I/path/to/range-v3/include fibonacci_range_v3.cpp
// GCC:   g++ -std=c++17 -I/path/to/range-v3/include fibonacci_range_v3.cpp
// MSVC:  cl /std:c++17 /permissive- /experimental:preprocessor /EHsc /I/path/to/range-v3/include fibonacci_range_v3.cpp

#include <iostream>
#include <range/v3/all.hpp>
#include "fibonacci.hpp"

int main()
{
    for (auto i : fibonacci() |
             ranges::views::take_while([](uint64_t x) {
                 return x < 10000;
             })) {
        std::cout << i << std::endl;
    }
    for (auto i : fibonacci() | ranges::views::take(20)) {
        std::cout << i << std::endl;
    }
}
