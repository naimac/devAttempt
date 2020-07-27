//  LTMInterfaces
#include <iostream>

class Event {};
class Point {};

// classe abstraite : une classe abstraite
// contient du code et des attributs
class Wnd {
private:
    Point hg, bd;
protected:
    // classe abstraite
    Wnd() {}
    virtual ~Wnd() {}
public:
    void show() {}
    void hide() {}
    virtual void draw() = 0;
};

// interface C++
class MouseEvent {
    // 0 attribut
public:
    virtual ~MouseEvent() {}
    
    // 3 comportements décrits
    virtual void mouseMove( Event ) = 0;
    virtual void mouseClick( Event ) = 0;
    virtual void mouseDoubleClick( Event ) = 0;
};

// héritage d'interfaces
class MouseEventExtended : public MouseEvent {
public:
    virtual void mouseTripleClick( Event ) = 0;
    virtual void mouseOver( Event ) = 0;
};

// classe concrete
class Window : public MouseEventExtended, public Wnd {
public:
    Window() {}
    virtual ~Window() {}
    
    // méthode de la classe abstraite
    virtual void draw() {}
    
    // méthodes implémentées des interfaces
    virtual void mouseMove( Event ){}
    virtual void mouseClick( Event ){}
    virtual void mouseDoubleClick( Event ){}
    virtual void mouseTripleClick( Event ) {}
    virtual void mouseOver( Event ) {}
};

int main() {
    Window w1;
    
    return 0;
}
