#include <iostream>
#include <future>
#include <thread>

int fun(int x) {
	x++;
	x *= 10;
	std::cout << "id " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	return x;
}

struct PrintNum
{
    void operator()(int i) const
    {
        std::cout << i << '\n';
    }
};

int main()
{
	PrintNum()(12);
	std::packaged_task<int(int)> pt(fun);         // 将函数打包起来
	std::future<int> fu = pt.get_future();        // 并将结果返回给future
	// std::thread t(std::ref(pt), 1);
	std::thread t(std::move(pt), 1);
	std::cout << fu.get() << std::endl;
	std::cout << "main id " << std::this_thread::get_id() << std::endl;
	t.join();
	return 0;
}