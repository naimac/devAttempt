//
//  main.cpp
//  LTMSemaphore
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>

using namespace std;

class semaphore{
private:
    mutex mtx;
    condition_variable cv;
    std::atomic_int _count;
    
public:
    semaphore(int count = 0):_count(count){}
    void release()
    {
        unique_lock<mutex> lck(mtx);
        ++_count;
        cv.notify_one();
    }
    void wait()
    {
        unique_lock<mutex> lck(mtx);
        while(_count == 0){
            cv.wait(lck);
        }
        _count--;
    }
};

semaphore sem1(3);

void fctThread() {
    sem1.wait();
    std::cout << "fctThread -> " << std::this_thread::get_id() << std::endl;
    std::chrono::milliseconds s(3000);
    std::this_thread::sleep_for(s);
    sem1.release();
}

int main() {
    
    std::thread t1(fctThread);
    std::thread t2(fctThread);
    std::thread t3(fctThread);
    std::thread t4(fctThread);
    std::thread t5(fctThread);
    std::thread t6(fctThread);
    std::thread t7(fctThread);
    std::thread t8(fctThread);
    std::thread t9(fctThread);
    std::thread t10(fctThread);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    
    return 1;
}


















