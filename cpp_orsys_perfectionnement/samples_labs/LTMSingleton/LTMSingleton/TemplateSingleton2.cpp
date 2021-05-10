//
//  TemplateSingleton.cpp
//  LTMSingleton
#include <iostream>

template <typename T> class Singleton {
public:
    static T& getInstance() {
        static T instance; // initialize the first time // C++11
        return instance; // destruction = end of the program
    }
    
    // C++11, here no copy and move
    Singleton<T>(const Singleton&) = delete;
    Singleton<T>& operator= (const Singleton) = delete;
    Singleton<T>(Singleton&&) = delete;
    Singleton<T>& operator= (Singleton&&) = delete;
    
protected:
    Singleton() {}
    virtual ~Singleton() { }

};

class X {
public:
    void method() { std::cout << this << " method" << std::endl; }
};

int main() {
    
    X& x1 = Singleton<X>::getInstance();
    X& x2 = Singleton<X>::getInstance();
    x1.method();
    x2.method();
    
    return 0;
}


























