#include <iostream>

template<typename ...Args>
auto sum(Args ...args)
{
    // return (args + ... + 0);
    return (args + ... + 0);
}

int main()
{
    auto a = sum(1, 2, 3, 5);
    std::cout << a << std::endl;
    sum();
    return 0;
}