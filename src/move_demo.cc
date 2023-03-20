#include <iostream>

class A
{
public:
    int v;
    int * v_p;
public:
    A();
    A(int v);
    A(const A& a);
    A(A&& a);

    ~A();
};

A::A()
{
    v_p = new int;
    *v_p = 2;
    std::cout << "default Constructor" << std::endl;
}

A::A(int v)
: v(v)
{
    v_p = new int;
    *v_p = v;
    std::cout << "Constructor " << *v_p << std::endl;
}

A::A(const A& a)
: v_p(new int)
{
    *v_p = *a.v_p;
    std::cout << "Copy Constructor " << *v_p << std::endl;
    this->v = a.v;
}

A::A(A&& a)
: v_p(a.v_p)
{   
    a.v_p = nullptr;
    std::cout << "Move Constructor " << *v_p << std::endl;
}

A::~A()
{
    std::cout << "delete v_p" << std::endl;

    delete v_p;
    
}

int main()
{
    A a;
    a.v = 1;

    A b = a;
    A c = std::move(b);
    A d(std::move(a));
    return 0;
}