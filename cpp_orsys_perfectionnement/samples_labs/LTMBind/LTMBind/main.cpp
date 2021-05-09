//  main.cpp
//  LTMBind
#include <iostream>
#include <thread>
#include <mutex>

std::mutex _m1;

class Tache {
public:
    void run() {
        std::unique_lock<std::mutex> lck(_m1);
        
        std::cout << "entree : " << std::this_thread::get_id() << std::endl;
        std::chrono::seconds s(3);
        std::this_thread::sleep_for(s);
        std::cout << "sortie : " << std::this_thread::get_id() << std::endl;
    }
};

int main() {
    Tache task1;
    std::thread t1, t2;
    t1 = std::thread{ std::bind(&Tache::run, task1) };
    t2 = std::thread{ std::bind(&Tache::run, task1) };
    t1.join();
    t2.join();
    
    return 0;
}
