// #include <fmt/core.h>
#include <iostream>
#include <tuple>
#include <utility>
// loop a tuple
// template<typename... Ts>
template<typename T>
// void print(const std::tuple<Ts...>& tu)
void print(const T& tu)
{
    // constexpr int N = sizeof...(Ts);
    // constexpr int N = std::tuple_size_v<std::remove_reference_t<decltype(tu)>>;
    constexpr int N = std::tuple_size_v<T>;
    [&]<size_t... I>(std::index_sequence<I...>) {
        std::cout << "[";
        // fold expression c++17
        (..., (std::cout << std::get<I>(tu) << (I != N-1 ? ", " : "")));
        std::cout << "]\n";
        
    }(std::make_index_sequence<N>());
}


int main()
{
    std::tuple tu(1, "zhaoqiu", "❤", "$");
    int a = -1;
    std::cin >> a;
    std::tuple tu2(a);
    print(tu2);
    return 0;
}