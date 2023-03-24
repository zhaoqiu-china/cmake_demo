#include <iostream>
#include <string>
#include <type_traits>

// parameter pack
// in function
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


// in class
// three-sections : avoid to define a class contains 0 teplate parameter

// forword declaration
template<typename... Args>
struct Sum;

// basic declaration
template<typename First, typename... Rest>
struct Sum<First, Rest...>
{
    enum {value = Sum<First>::value + Sum<Rest...>::value};
};

// recursion termination
template<typename Last>
struct Sum<Last>
{
    enum {value = sizeof(Last)};
};

// two-sections : also avoid to define a class contains 0 teplate parameter
template<typename First, typename... Rest>
struct Sum2
{
    enum {value = Sum2<First>::value + Sum2<Rest...>::value};
};

template<typename Last>
struct Sum2<Last>
{
    enum { value = sizeof(Last)};
};

// other example for recursion termination
// template<typename T1, typename T2>
// struct Sum2<T1, T2>
// {
//     enum { value = Sum2<T1>::value + Sum2<T2>::value };
// };

// ommit "value" by using std::intergral_constant
template<typename... Args>
struct Sum3;

template<typename First, typename... Rest>
struct Sum3<First, Rest...> : std::integral_constant<int, Sum3<First>::value + Sum3<Rest...>::value>
{
    
};

template<typename Last>
struct Sum3<Last> : std::integral_constant<int, sizeof(Last)>
{

};

// 继承模式展开参数包
// https://www.cnblogs.com/qicosmos/p/4325949.html
// https://en.cppreference.com/w/cpp/language/parameter_pack#Expansion_loci


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

    Sum<int, float, double> a;
    std::cout << "the size of Sum : " << a.value << std::endl;
    std::cout << "the size of Sum : " << Sum<int, float, double>::value << std::endl;


    std::cout << "the size of Sum3 : " << Sum3<int, float, char>::value << std::endl;

    return 0;
}