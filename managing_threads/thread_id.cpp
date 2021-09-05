#include <iostream>
#include <thread>

void f1(const std::thread::id& mt) {
    if(std::this_thread::get_id()==mt)
        std::cout << "f1: master thread" << std::endl;
    else
        std::cout << std::this_thread::get_id();
}

int main() {
    std::thread::id master_thread = std::this_thread::get_id();
    /*f1(master_thread);*/
    std::thread t{f1, std::ref(master_thread)};
    t.join();

    return 0;
}