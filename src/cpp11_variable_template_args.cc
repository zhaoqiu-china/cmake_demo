#include <iostream>
#include <string>

template<typename... T>
void my_print(T... args)
{
    std::cout << sizeof...(args) << std::endl;
}
// 1. By Recursion
// recursive termination function
template<typename T>
T sum_recursive(const T t)
{
    return t;
}

template<typename T, typename... Ts>
T sum_recursive(const T first, Ts... rest)
{
    return first + sum_recursive(rest...);
}

// recursive termination function
void print_recursive()
{
    std::cout << "empty" << std::endl;
}

template<typename T, typename... Args>
void print_recursive(const T first, Args... rest)
{
    std::cout << "value: " << first << std::endl;
    print_recursive(rest...);
}

// 2. By comma operator
// d = (a = b, c);  the brackets will return c to d after b is assigned to a, because of comma operator which can cause a sequence of oprations to be performed.
// demo1
template<typename T>
void printarg(const T& t)
{
    std::cout << t << std::endl;
}

template<typename ...Args>
void expand(Args... args)
{
    int arr[] = {(printarg(args), 0)...};
}

// demo2
template<typename F, typename ...Args>
void expand2(const F& f, Args&&... args)
{
    std::initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
}

int main()
{
    my_print();
    my_print(0);
    my_print(0, "zhaoqiu");

    int rev = sum_recursive(1, 2, 3, 4);
    double r = sum_recursive(1.2);
    std::cout << rev << std::endl;
    std::cout << r << std::endl;

    print_recursive(1, "zhaoqiu", 1.333);

    expand("comma", "ok", 11);

    expand2([](std::string s){std::cout << s << std::endl;}, "zhaoqiu", "age: ", "27");

    expand2([](auto v){std::cout << v << std::endl;}, "my age: ", 27);
    return 0;
}