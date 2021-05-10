//

#include <iostream>
#include <thread>
#include <atomic>

std::mutex m1;

/*
 void fct2WithParam( int i ) {
 m1.lock();
 std::cout << "thread - fct2WithParam, " << i << std::endl;
 m1.unlock();
 }*/

void fct() {
    m1.lock();
    
    std::cout << "thread - fct" << std::endl;
    
    std::cout << std::this_thread::get_id() << std::endl;
    std::chrono::seconds s(1);
    std::this_thread::sleep_for(s);
    
    m1.unlock();
}

class X {};

int main() {

    std::cout << std::this_thread::get_id() << std::endl;

    std::thread t1{fct};
    std::thread t2{fct};
    
    /*int i  =2;
    std::thread t3{std::bind(fct2WithParam, i)};*/
    
    t1.join();
    t2.join();
    //t3.join();
    
    // atomic
    std::atomic_int i (1);
    std::atomic<int> j;
    
    std::atomic<X> x1;
    
    return 0;
}

