#include <iostream>
#include <thread>

void print(const std::string& str)
{
    std::cout << "from print: " << str << std::endl;
}

int main()
{
    std::thread t1(print, "hello world.");
    t1.join();
    return 0;
}