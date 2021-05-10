//
//  main.cpp
//  LTMDefaultDelete
//
//  Created by bleclercq on 13/02/2015.
//  Copyright (c) 2015 LTM. All rights reserved.
//

#include <iostream>

class X {
public:
    X() = delete;
    X(long) {};
    X( const X& ) = default;
    X& operator =( const X& ) = delete;
};

int main() {

    X x1;     // KO
    
    X x2(5);    // OK
    
    X x4( x2 ); // OK
    
    x2 = x4;    // KO
    
    return 0;
}
