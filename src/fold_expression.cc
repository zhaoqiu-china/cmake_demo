#include <iostream>

template<typename ...Args>
auto sum(Args ...args)
{
    return (args + ... + 0);
}

int main()
{
    sum(1, 2, 3, 5);
    sum();
    return 0;
}