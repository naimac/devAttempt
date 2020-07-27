//
//  main.cpp
//  LTMSemaphoreBoost
//

#define BOOST_DATE_TIME_NO_LIB

#include <iostream>
#include <thread>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>

using namespace std;
using namespace boost::interprocess;

interprocess_semaphore semaphore1(3);

// thread
void fct() {
    semaphore1.wait();
    
    cout << this_thread::get_id() << " , je prends le sémaphore" << endl;
    std::chrono::seconds s(3);
    std::this_thread::sleep_for(s);
    cout << this_thread::get_id() << " , je relache le sémaphore" << endl;

    semaphore1.post();
}

int main(int argc, const char * argv[]) {
    
    std::thread tableau[10];
    
    // création
    for( int t = 0; t < 10; t++ ) {
        tableau[t] = std::thread { fct };
    }
    
    // join
    for( int t = 0; t < 10; t++ ) {
        tableau[t].join();
    }

    return 0;
}
