#include <iostream>
#include <thread>

void a() {
    std::cout << 'a' << std::endl;
}

void b() {
    std::cout << 'b' << std::endl;
}

int main() {
    std::thread t1{a};
    std::thread t2 = std::move(t1);
    t1 = std::thread{b};
    std::thread t3 = std::move(t2);
    t1.join();
    t1 = std::move(t3);
    t1.join();
    /*t2.join();*/
    /*t3.join();*/
    return 0;
}
