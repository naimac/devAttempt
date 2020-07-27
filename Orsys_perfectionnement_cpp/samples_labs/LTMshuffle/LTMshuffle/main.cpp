//
//  main.cpp
//  LTMshuffle
#include <iostream>
#include <algorithm>    // std::shuffle
#include <array>
#include <random>
#include <chrono>       // std::chrono::system_clock

int main () {
    std::array<int,5> foo {1,2,3,4,5};
    
    // seed
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    
    shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
    
    std::cout << "mélange :";
    for (int& x: foo) std::cout << ' ' << x;
    std::cout << '\n';
    
    return 0;
}
