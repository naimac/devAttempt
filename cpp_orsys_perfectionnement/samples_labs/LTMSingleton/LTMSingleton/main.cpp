//  main.cpp
//  LTMSingleton
#include <iostream>
#include <mutex>

// Singleton
class Printer {
private:
    static Printer * _instance;
    static std::mutex _m1;

    Printer() {}
    virtual ~Printer() {}
public:
    static void reset() {
        // désactiver le singleton
        m1.lock();
        delete _instance;
        _instance = nullptr;
        m1.unlock();
    }
    
    static Printer * getInstance() {
        _m1.lock();
        if( nullptr == _instance )
            //cs
            _instance = new Printer();
        
        _m1.unlock();
        
        return _instance;
    }
};

Printer * Printer::_instance = nullptr;

void LiberationDeMonProgramme() {
    // le bon moment pour détruite l'objet à la fin du main
    Printer::reset();
}

void myPart() {
    Printer * pp = Printer::getInstance();
    //...
    atexit(LiberationDeMonProgramme);
}
//

int main() {
    //...
    myPart();
    
    return 0;
}












