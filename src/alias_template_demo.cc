#include <iostream>
#include <ratio>
#include <vector>

// template<typename T, template<class> class Container> is also ok
template<typename T, template<class T> class Container>
class WrapperContainer
{
private:

public:
    Container<T> cont_;

public:
    void push_back(const T& t) {
        cont_.push_back(t);
    }
    // WrapperContainer();
    // ~WrapperContainer();
};




template<typename T>
using Vec = std::vector<T>;

int main()
{
    using two_third = std::ratio<2, 3>;
    using one_sixth = std::ratio<1, 6>;

    using product = std::ratio_multiply<two_third, one_sixth>;

    std::cout << product::num << " / " << product::den << std::endl;

    typedef void (*fun)(int, int);  // deprecated
    using fun2 = void (*)(int, int);  // recommended

    WrapperContainer<int, Vec> w1;
    w1.push_back(1);

}