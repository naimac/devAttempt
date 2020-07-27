//
//  main.cpp
//  LTMdynamic_castExo
#include <iostream>

// Analysez cette architecture
class Object {
public:
    Object() {}
    // Créez le destructeur ici
    virtual ~Object() {}
};

class A : public virtual Object {
public:
    A() {}
    ~A() {}
};

class B : virtual public Object {
public:
    B() {}
    ~B() {}
};

class D : public A, public B {
public:
    D() {}
    ~D() {}
};

class Base {
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() {}
    virtual ~Derived() {}
    virtual void name() {}
};

int main()
{
    // Soit les allocations suivantes ...
    D d;
    A * pa = &d; // upcasting !
    
    // 1. Caster le pointeur pa dans un D* en utilisant dynamic_cast
    // 1 bis. Afficher le résultat de l'opération et constater
    D * new_d = dynamic_cast<D*>(pa);
    if( new_d )
        std::cout << "new_d ok" << std::endl;
    else
        std::cout << "new_d ko" << std::endl;
    
    // 2. Caster le pointeur pa dans un B* en utilisant dynamic_cast
    // 2 bis. Afficher le résultat de l'opération et constater
    B * new_b = dynamic_cast<B*>(pa); // sidecast avec dynamic_cast
    if( new_b ) {
        std::cout << "new_b ok" << std::endl;
    }else
        std::cout << "new_b ko" << std::endl;
    
    B b3;
    // 3. Caster b3 (son adresse) dans un A* en utilisant dynamic_cast
    // 3 bis. Afficher le résultat de l'opération et constater
    A * new_a = dynamic_cast<A*>(&b3);
    if( new_a ) {
        std::cout << "new_a ok" << std::endl;
    }else
        std::cout << "new_a ko" << std::endl;
    
    Base * b1 = new Base();
    // 4. Caster le pointeur b1 dans un Derived * en utilisant dynamic_cast
    // 4 bis. Afficher le résultat de l'opération et constater
    if (Derived * d = dynamic_cast<Derived*>(b1)) {
        std::cout << "downcast ok" << std::endl;
        d->name(); // ok
    }
    
    Base * b2 = new Derived();
    // 5. Caster le pointeur b2 dans un Derived * en utilisant dynamic_cast
    // 5 bis. Afficher le résultat de l'opération et constater
    if(Derived * d = dynamic_cast<Derived*>(b2)) {
        std::cout << "Base -> Derived OK" << std::endl;
        d->name(); // ok
    }
    
    // destructions
    delete b1; b1 = nullptr;
    delete b2; b2 = nullptr;
    
    return 0;
}
