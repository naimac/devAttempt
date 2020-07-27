//
//  main.cpp
//  LTMOperateur
//
//  Created by bleclercq on 06/02/2015.
//  Copyright (c) 2015 LTM. All rights reserved.
//

#include <iostream>

class String;

class Tableau {
public:
    
};

class String {
private:
    char * _ptr;
public:
    String() : _ptr(nullptr) {}
    ~String() {}
    
    operator Tableau();
    
    operator const char *() const {
        return _ptr;
    }
    
    const char * get() const {
        return _ptr;
    }
};

int main() {
    
    String s1;
    
    Tableau t = s1;
    
    const char * p = s1;    // OK
    char * p = s1;          // KO
    std::cout << s1;        // OK
    
    return 1;
}

/*class Figure {
public:
    Figure() {}
    ~Figure() { std::cout << "Figure::~Figure()" << std::endl; }
};

class Rectangle : public Figure {
public:
    Rectangle() {}
    ~Rectangle() { std::cout << "Rectangle::~Rectangle()" << std::endl; }
};


int main() {
    
    Figure * pf = new Rectangle();
    //...
    delete pf;
    
    return 0;
}*/
