//
//  main.cpp
//  LTMClasseImbriquee

#include <iostream>

class smart_ptr {
private:
    class cpt {
    public:
        cpt();
        ~cpt() {}
        int c;
    };
    
    cpt * _pc;
public:
    smart_ptr();
    virtual ~smart_ptr() {}
};

smart_ptr::smart_ptr() : _pc( new cpt() ) {
    //...
}

smart_ptr::cpt::cpt() : c(0) {
    //...
}

int main() {
    
    
    
    return 0;
}

