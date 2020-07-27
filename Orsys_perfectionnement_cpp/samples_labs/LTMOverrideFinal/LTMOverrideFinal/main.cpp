//
//  main.cpp
//  LTMOverrideFinal
//
//  Created by bleclercq on 16/02/2015.
//  Copyright (c) 2015 LTM. All rights reserved.
//

#include <iostream>

class A {
public:
    virtual void fctA() {}
    void fctB() {}                      // non virtual
    virtual void fctC() {}
    virtual void fctD(char) {}
    
    // final
    virtual void fctE() final;
    void fctF();
};

class B : public A {
public:
    void fctA() override {}                 // OK
    //void fctB() override {}               // KO
    //virtual void fctC(int) override {}    // KO
    virtual void fctD(char) override {}
    
    //virtual void fctE();                  // KO
    void fctF();
};

int main() {
    
    //...
    
    
    return 0;
}
