//
//  main.cpp
//  LTMRValueReference
//
#include <iostream>
#include <utility>
#include <vector>

class X {};

X f() {
    X x1;
    return x1;
}

template<class T> void swap(T& ra, T& rb)	// swap
{
    T tmp = std::move(ra);	// ra bouge vers tmp
    ra = std::move(rb);		// rb bouge vers ra
    rb = std::move(tmp);		// tmp bouge vers rb
}

int main() {
    // ref classique
    X a, b;
    X & ref = a;
    //X & ref2 = f(); // KO
    
    // rvalue reference
    X&& rvr = f(); // OK
    
    // swap
    swap<X>( a, b );
    
    // move operator (utility)
    std::string foo = "orsys";
    std::string bar = "ltm";
    std::vector<std::string> v1;
    
    v1.push_back (foo);                    // copies
    v1.push_back (std::move(bar));         // moves
    
    std::cout << "vector contient :";
    for(std::string& x:v1)
        std::cout << ' ' << x << std::endl;
    
    std::cout << "foo = " << foo << std::endl;
    std::cout << "bar = " << bar << std::endl;
        
    return 0;
}
