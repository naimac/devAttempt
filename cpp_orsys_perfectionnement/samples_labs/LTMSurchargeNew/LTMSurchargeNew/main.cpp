//
//  main.cpp
//  LTMSurchargeNew
#include <iostream>

class X {
    int i, j;
public:
    X() {
    }
    
    virtual ~X() {
    }
    
    void * operator new(size_t taille) {
        //
        return malloc(taille);
    }
    
    void operator delete( void * p ) {
        free(p);
    }
};

int main() {
    X * px = new X();
    //...
    delete px;
    
    px = nullptr;
    
    return 0;
}

















