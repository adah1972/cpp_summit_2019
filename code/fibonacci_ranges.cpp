// GCC: g++ -std=c++17 -fconcepts -I/path/to/cmcstl2/include fibonacci_ranges.cpp

#include <iostream>
#include <experimental/ranges/ranges>
#include "fibonacci.hpp"

int main()
{
    namespace ranges = std::experimental::ranges;
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
