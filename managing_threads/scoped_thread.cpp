#include <iostream>
#include <thread>

struct func {
    unsigned i;
    func(int i_):i(i_){}
    void operator()()
    {
        for(unsigned j=0;j<i;++j) {}
    }
        };

class scoped_thread {
    std::thread t;
public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_)) {
        if (!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread() {
        t.join();
    }
    scoped_thread(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;
};

int main() {
    func f(700000000);
    std::cout << "ok1" << std::endl;
    scoped_thread t(std::thread{f});
    std::cout << "ok2" << std::endl;
    return 0;
}