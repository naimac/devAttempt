//
//  main.cpp
//  LTMAntiPatterns
//

#include <iostream>

class Figure {
public:
    Figure() {
        draw();
    }
    virtual ~Figure() {}
    virtual void draw() = 0;
};

class Rectangle : public Figure {
private:
    double _hg, _bd;
public:
    Rectangle() {}
    ~Rectangle() {}
    virtual void draw() {}
};

int main() {

    Figure * p = new Rectangle();
    //...
    delete p;
    p = nullptr;
    
    return 0;
}
