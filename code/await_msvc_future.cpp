// MSVC: cl /std:c++17 /await /EHsc await_future.cpp

#include <future>
#include <iostream>
#include <experimental/coroutine>

using namespace std;

future<int> compute_value()
{
    int result = co_await async([] { return 42; });
    co_return result;
}

int main()
{
    auto value = compute_value();
    cout << value.get() << endl;
}
