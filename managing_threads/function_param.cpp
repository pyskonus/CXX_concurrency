#include <iostream>
#include <thread>

void f(std::thread t) {
    t.join();
}

void a() {
    std::cout << "a" << std::endl;
}

int main() {
    /*f(std::thread(a));*/
    std::thread t(a);
    f(std::move(t));
    return 0;
}