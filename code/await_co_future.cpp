// Clang: clang++ -std=c++17 -fcoroutines-ts await_co_future.cpp

#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <experimental/coroutine>

using namespace std;
using std::experimental::coroutine_handle;
using std::experimental::coroutine_traits;

template <typename T>
struct co_future : future<T> {
    using future<T>::get;
    using future<T>::wait;
    using future<T>::wait_for;

    co_future(future<T>&& fut) : future<T>(std::move(fut)) {}

    bool await_ready()
    {
        return wait_for(std::chrono::seconds(0)) ==
               std::future_status::ready;
    }

    void await_suspend(coroutine_handle<> handle)
    {
        wait();
        handle.resume();
    }

    auto await_resume()
    {
        return get();
    }
};

template <typename T, typename... Args>
struct coroutine_traits<co_future<T>, Args...> {
    struct promise_type {
        promise<T> promise_;
        co_future<T> get_return_object()
        {
            return promise_.get_future();
        }

        auto initial_suspend() { return suspend_never(); }
        auto final_suspend() { return suspend_never(); }

        template <typename U>
        void return_value(U&& value)
        {
            promise_.set_value(std::forward<U>(value));
        }

        void unhandled_exception()
        {
            promise_.set_exception(current_exception());
        }
    };
};

template <typename T>
auto co_async(T&& func)
{
    return co_future(async(std::forward<T>(func)));
}

co_future<int> compute_value()
{
    int result = co_await co_async([] { return 42; });
    co_return result;
}

int main()
{
    auto value = compute_value();
    cout << value.get() << endl;
}
