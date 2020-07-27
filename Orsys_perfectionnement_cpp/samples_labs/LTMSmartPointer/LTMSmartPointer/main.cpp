//
//  main.cpp
//  LTMSmartPointer
//
#include <iostream>

class X {
private:
    
public:
     ~X() {}
    X() {}
    
    static X * create() {
        return new X();
    }
    void Methode() {}
    void foo() { std::cout << "foo" << std::endl; }
};

int main() {
    
    std::shared_ptr<X> sp1 = std::make_shared<X>();
    //std::shared_ptr<X> sp1( X::create() ); // L'objet vient d'être crée,
    // le compteur est à 1
    
    std::shared_ptr<X> sp2( sp1 );     // 2 smarts pointers pointent
    // notre objet, compteur = 2
    
    std::shared_ptr<X> sp3;
    sp3 = sp1;                    // compteur = 3
    
    std::cout << "sp3.count = " << sp3.use_count() << std::endl; // Le compteur est à 3 !
    
    // le compteur de sp3 = 3
    sp3.reset(); // -1  sur le compteur ici
    if( !sp3 ) {
        std::cout << "!sp3 KO" << std::endl;
    }
    std::cout << "sp3.count = " << sp3.use_count() << std::endl; // compteur = 0
    std::cout << "sp2.count = " << sp2.use_count() << std::endl; // compteur = 0
    
    // Le compteur de sp6 est à 2
    std::weak_ptr<X> sp6( sp1 );
    std::cout << sp6.use_count() << std::endl; // Ici le compteur est toujours à 2
    
    if( sp6.lock() ) { // test
        std::cout << "sp6.lock()" << std::endl;
    }else if( sp6.expired() ) {
        std::cout << "sp6.expired()" << std::endl;
    }
    
    sp1.reset();
    sp2.reset();
    sp3.reset();
    
    std::cout << sp6.use_count() << std::endl;
    
    std::shared_ptr<X> temp = sp6.lock();
    if( temp ) { // test
        std::cout << "sp6.lock()" << std::endl;
    }else if( sp6.expired() ) {
        std::cout << "sp6.expired()" << std::endl;
    }
    
    std::cin.get();
    
    return 0;
}













template <class truc> class auto_var {
private:
    truc * _p;
public:
    // pas de copie autorisée
    auto_var( const auto_var& ) = delete;
    auto_var& operator =( const auto_var& ) = delete;
    
    auto_var( truc * pp = nullptr ) : _p(pp) {}
    
    ~auto_var() {
        delete _p;
        _p = nullptr;
    }
    
    truc * get() const {
        return _p;
    }
    
    truc * operator ->() const {
        return _p;
    }
    
    truc& operator *() const {
        return *_p;
    }
    
    void reset() {
        this->~auto_var();
     }
};

/*int main() {
    
    //
    X * p = new X();
    // ...
    delete p;
    p = nullptr;
    
    // allocation avec un smart pointer
    auto_var<X> sp( new X() );
    sp->method();
    
    return 0;
}*/
