//
//  main.cpp
//  LTMatomic
//
#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

std::mutex m1;

std::atomic_int gi;
int gi2 = 0;

void monthread() {
    for( int t = 0; t < 10000; t++ ) {
        m1.lock();
        gi2++;
        m1.unlock();
        
        ::gi++;
    }
}

int main() {
    std::thread tab[10];
    
    for( int t = 0; t < 10; t++ )
        tab[t] = std::thread{ monthread };
    
    for( int t = 0; t < 10; t++ )
        tab[t].join();
    
    std::cout << "gi = " << ::gi << " , gi2 = " << gi2 << std::endl;
    
    return 0;
}
