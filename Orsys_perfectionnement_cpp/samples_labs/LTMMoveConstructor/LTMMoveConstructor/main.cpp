//
//  main.cpp
//  LTMMoveConstructor
//

#include <iostream>

struct A {
    std::string s;
    A() : s("test") {}
    // move ctor
    A(A&& o) : s(std::move(o.s)) {}
};

A f() {
    A a;
    return a;
}

int main() {
    A a2;
    A a1( f() ); // move
    
    return 0;
}
