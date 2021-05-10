
#include <iostream>
#include <memory>

class String {
    // ...
private:
    String() {}
    
public:
    static String * create() { // factory
        return new String();
    }
    
    ~String() {}
    const char * afficher() {
        // ...
        return "test";
    }
};

class Object {};

// implémenter un smart pointeur sous forme de template
// surcharger l’opérateur -> et *. créer la méthode get() qui
// retour le pointeur et créer la méthode reset().

template <class truc> class auto_var {
private:
    truc * p = nullptr;
    
    auto_var( const auto_var& ) = delete;
    auto_var& operator = (const auto_var&) = delete;
public:
    auto_var() {}
    
    // principal ctor
    auto_var( truc * pp ) : p(pp) {}
    
    ~auto_var() {
        if( nullptr != p ) {
            delete p;
            p = nullptr;
        }
    }
    
    void reset() {
        delete p;
        p = nullptr;
        // this est ok
    }
    
    truc * operator ->() const {
        return p;
    }
    
    truc & operator *() const {
        return *p;
    }
    
    truc * get() const { return p; }
    
    // Opérateur de conversion de type
    operator truc *() const {
        return p;
    }
};

template <class T> void fonction(T * p) {
    //
}

// handler or smartpointer
int main() {
    
    // Implémenter le template auto_var (sans copie), tel que
    String s2;
    auto_var<String> sp1( new String() );
    
    //auto_var<String> sp1( String::create() );
    /*auto_var<String> sp1( ps );
    auto_var<String> sp3( ps );*/
    
    //String * ps = sp1;
    
    sp1->afficher();
    (*sp1).afficher();
    
    auto_var<String> sp2( String::create()  );
    
    fonction<String>(sp2); // mauvaise pratique
    fonction<String>(sp2.get()); // bonne pratique
    
    return 0;
}













