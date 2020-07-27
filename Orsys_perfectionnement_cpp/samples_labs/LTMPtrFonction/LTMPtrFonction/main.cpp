//
//  main.cpp
//  LTMPtrFonction

#include <iostream>

int fct( int i ) {
    return i*i;
}
int fct2( int i ) {
    // autre cas
    return i*i;
}

typedef int (*ptrFct1)(int);

int main(int argc, const char * argv[]) {

    ptrFct1 pf1 = fct2;
    int ret = pf1(2);
    
    return 0;
}
