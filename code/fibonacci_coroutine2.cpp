// Clang: clang++ -std=c++17 fibonacci_coroutine2.cpp -lboost_context-mt
// GCC:   g++ -std=c++17 fibonacci_coroutine2.cpp -lboost_context
// MSVC:  cl /std:c++17 /EHsc fibonacci_coroutine2.cpp

#include <iostream>
#include <stdint.h>
#include <boost/coroutine2/all.hpp>

typedef boost::coroutines2::coroutine<const uint64_t> coro_t;

void fibonacci(coro_t::push_type& yield)
{
    uint64_t a = 0;
    uint64_t b = 1;
    while (true) {
        yield(b);
        auto tmp = a;
        a = b;
        b += tmp;
    }
}

int main()
{
    for (auto i : coro_t::pull_type(
             boost::coroutines2::fixedsize_stack(),
             fibonacci)) {
        if (i >= 10000) {
            break;
        }
        std::cout << i << std::endl;
    }
}
