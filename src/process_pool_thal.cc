#include <iostream>
#include <vector>

void f(int& n)
{
    n++;
}

template<typename F, typename List>
void parallel_exec(const F& f, const List& list)
{
    for(auto l : list) {
        f(l);
    }
}

template<typename List>
void loop_list(const List& list)
{
    for(auto ele : list) {
        std::cout << ele << std::endl;
    }
}

int main()
{
    std::vector<int> a{1, 2, 3};
    int b[10] = {0};
    // loop_list(b);
    parallel_exec(f, a);
    return 0;
}