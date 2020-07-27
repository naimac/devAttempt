//
//  main.cpp
//  LTMHeritagePrive
//
//  Created by bleclercq on 10/02/2015.
//  Copyright (c) 2015 LTM. All rights reserved.
//

#include <iostream>


class A {
protected:
    int prot_A;
};

class B : private A {
protected:
    int prot_B;
};

class C : public B {
protected:
    int prot_C;
public:
    void method() {
        //prot_A = 1;
    }
};

int main() {

    A * pA = new C(); // upcasting interdit dans ce cas
    //...
    delete pA;
    pA = nullptr;
    
    return 0;
}
