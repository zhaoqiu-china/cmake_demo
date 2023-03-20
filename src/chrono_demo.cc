#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

template<typename T1, typename T2>
using mul = std::ratio_multiply<T1, T2>;

int main()
{
    using shakes = std::chrono::duration<int, mul<std::deca, std::nano>>;
    using jiffies = std::chrono::duration<int, std::centi>;

    using fps_24 = std::chrono::duration<double, std::ratio<1,24>>;

    std::cout << "1s = " << fps_24(1.5s).count() << " frames.";

    auto start = std::chrono::steady_clock::now();

    auto end = std::chrono::steady_clock::now();
    
    // long long int nano to double milli
    std::chrono::duration<double, std::milli> duration = end - start;
    // long long int nano to long long int milli using "cast"
    std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

    char * a[10];
    a[0] = "01234";
    a[1] = "4321";
    auto b = a[1][0];

    return 0;
}