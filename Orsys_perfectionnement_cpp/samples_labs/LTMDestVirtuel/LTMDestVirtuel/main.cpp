//  main.cpp
//  LTMDestVirtuel
#include <iostream>

class FigureGeo {
private:
    int i;
public:
    FigureGeo(int ii) :i(ii) {
        method();
    }
    void method() {
        draw();
    }
    virtual void draw() = 0;
    virtual void move() = 0;
    
    virtual ~FigureGeo() {
        std::cout << "FigureGeo::~FigureGeo" << std::endl;
    }
};

class Cercle : public FigureGeo {
    // champs
    int rayon;
public:
    Cercle(int ii = 0) : FigureGeo(ii), rayon(ii) {}
    virtual ~Cercle() { std::cout << "Cercle::~Cercle" << std::endl; }
    virtual void draw() {
        //FigureGeo::draw();
        //... dessin du cercle
    }
    virtual void move()  {}
};

int main() {
    Cercle c1;
    
    FigureGeo * pc = new Cercle();
    pc->draw();
    //...
    delete pc;
    pc = nullptr;
    
    return 0;
}
