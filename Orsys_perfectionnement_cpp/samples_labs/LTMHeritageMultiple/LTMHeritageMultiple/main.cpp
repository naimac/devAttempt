//
//  main.cpp
//  LTMHeritageMultiple
//
#include <iostream>

class O {
private:
    int membre;
public:
    O() : membre(-999) { std::cout << "O::O()" << std::endl; }
    virtual ~O() {}
};

class A : public O {
private:
    int membre_A;
public:
    A() : membre_A(-888) { std::cout << "A::A()" << std::endl; }
    ~A() {}
    void print_this() {
        std::cout << this << std::endl;
    }
};

class B : public O {
private:
    int membre_B;
public:
    B() : membre_B(-777) { std::cout << "B::B()" << std::endl; }
    ~B() {}
    void print_this() {
        std::cout << this << std::endl;
    }
};

class C : public A, public B {
private:
    int membre_C;
public:
    C() : membre_C(-666) { std::cout << "C::C()" << std::endl; }
    ~C() {}
};

int main(int argc, const char * argv[]) {
    C c1;
    
    //c1.run();                              // KO
    static_cast<A*>(&c1)->print_this();    // OK
    static_cast<B*>(&c1)->print_this();    // OK
    
    return 0;
}
