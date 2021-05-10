//
//  main.cpp
//  LTMPeageC++11
//

#include <iostream>
#include <thread>
#include <mutex>
#include <random>

int const max_voiture = 256;
std::mutex verrou_peage;

// Thread
void voiture() {
    //verrou_peage.lock();
    std::unique_lock<std::mutex> lck(verrou_peage);
    std::cout << "la voiture " << std::this_thread::get_id() << ", entre pour payer" << std::endl;
   
    // random
    std::random_device rd;
    std::mt19937 gen( rd() ); // mersenne_twister_engine
    std::uniform_int_distribution<> dis(1, 6);
    auto s = dis(rd);
    std::cout << "secondes (random) = " << s << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(s));
    
    std::cout << "la voiture " << std::this_thread::get_id() << ", sort de la caisse" << std::endl;
    //verrou_peage.unlock();
}

//std::thread * tab[max_voiture];

int main() {
    int nb_voiture = 0;
    std::thread tab_thread[max_voiture];
    
    // nombre de cores ?
    std::cout << "nb cores : " << std::thread::hardware_concurrency() << std::endl << std::endl;
    
    std::cout << "Entrez le nombre de voiture ?" << std::endl;
    std::cin >> nb_voiture;
    
    if( nb_voiture > 0 && nb_voiture < max_voiture ) {
        //
        for( int t = 0; t < nb_voiture; t++ ) {
            tab_thread[t] = std::thread{ voiture };
        }
        
        for ( int i=0; i < nb_voiture; i++ ) {
            tab_thread[i].join();
        }
    }else {
        std::cout << "cas invalide" << std::endl;
    }
    
    return 0;
}