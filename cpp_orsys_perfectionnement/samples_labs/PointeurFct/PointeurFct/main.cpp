//
//  main.cpp
//  PointeurFct

#include <iostream>

int fct( int );
int fct2( int );

typedef int (*PTRF) (int);

int main(int argc, const char * argv[]) {

    PTRF pf = fct;
    
    auto p = fct2;


    return 0;
}
