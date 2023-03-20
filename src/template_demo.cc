#include <iostream>

template<typename T>
struct ListNode {
    T val;
    ListNode *next;
    ListNode(T x) : val(x), next(NULL) {}
};

int main()
{
    ListNode l{1};
    std::cout << l.val << std::endl;
    return 0;
}