#include <mutex>

class deleted_copy_func
{
private:
    int m_Value;
    std::mutex m_Mutex;
public:
    deleted_copy_func(int value): m_Value(value) {};
    ~deleted_copy_func() {};

    deleted_copy_func(const deleted_copy_func&) = delete;
    deleted_copy_func& operator=(const deleted_copy_func&) = delete;
};

int main()
{
    deleted_copy_func d1{1};
    // can't use "delete" function
    // auto d2 = d1;
    // auto d2(d1);

    return 0;
}