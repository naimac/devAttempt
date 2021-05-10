//
//  main.cpp
//  LTMCPP11
//
//  Created by bleclercq on 12/02/2015.
//  Copyright (c) 2015 LTM. All rights reserved.
//

#include <iostream>

int method(int i) {
    return i*i;
}

int main() {
    
    // int
    auto i = 2;
    i++;
    
    // bool
    auto b = false;
    b = true;
    
    // pointeur de fonction dans ce cas
    auto pf = method;
    i = pf(2);
    
    // types lambda et auto
    auto pfAdd = [](int a, int b) { return a+b; };
    int ret = pfAdd( 2, 3 );
    
    return 0;
}
