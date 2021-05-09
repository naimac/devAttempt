//
//  main.cpp, BL
//  LTMMoveAssignment
#include <iostream>
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

void pause_thread(int n) {
    std::this_thread::sleep_for (std::chrono::seconds(n));
    std::cout << "pause de " << n << " seconds\n";
}

// move assignment operator move (1) : thread& operator= (thread&& rhs) noexcept;
// http://www.cplusplus.com/reference/thread/thread/operator=/

int main() {    
    std::thread threads[5];
    
    std::cout << "5 threads...\n";
    for (int i = 0; i < 5; ++i){
        threads[i] = std::thread( pause_thread ,i+1 );   // move-assignment threads
    }
    
    std::cout << "Attente de join(s) ...\n";
    for (int i = 0; i < 5; ++i) {
        threads[i].join();
    }
    
    std::cout << "Fin threads terminés !\n";
    
    return 0;
}
