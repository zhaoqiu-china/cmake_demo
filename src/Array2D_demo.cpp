#include <iostream>
#include "include/Array2D.h"

int main()
{
    Array2D<int> a{10, 10};
    // a.fill(111);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            a(i, j) = i * 10 + j;
        }
        
    }
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << a(i, j) << std::endl;
        }
        
    }
    std::cout << a(1, 1) << std::endl;

    const int b = a(1, 1);
    auto c = a[1];

    std::cout << c[0] << std::endl;
    return 0;
}