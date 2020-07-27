//  main.cpp
//  LTMdynamic_castExo
#include <iostream>

// Analysez cette architecture
class Object {
public:
    Object() {}
    // Créez le destructeur ici
    ......... ~Object() {}
};

class A : virtual public Object {
public:
    A() {}
    .......... ~A() {}
};

class B : public virtual Object {
public:
    B() {}
    ......... ~B() {}
};

class D : public A, public B {
public:
    D() {}
    ........... ~D() {}
};

//
class Base {
public:
    Base() {}
    virtual ~Base() {}
};

class Derived: public Base {
public:
    Derived() {}
    virtual void name() {}
};

int main()
{
    // Soit les allocations suivantes ...
    D d;
    A * pa = &d; // upcasting
    
    // 1. Caster le pointeur pa dans un D* en utilisant dynamic_cast
    // 1 bis. Afficher le résultat de l'opération et constater
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    
    // 2. Caster le pointeur pa dans un B* en utilisant dynamic_cast
    // 2 bis. Afficher le résultat de l'opération et constater
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    
    B b3;
    // 3. Caster b3 (son adresse) dans un A* en utilisant dynamic_cast
    // 3 bis. Afficher le résultat de l'opération et constater
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    
    Base * b1 = new Base();
    // 4. Caster le pointeur b1 dans un Derived * en utilisant dynamic_cast
    // 4 bis. Afficher le résultat de l'opération et constater
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    
    Base * b2 = new Derived();
    // 5. Caster le pointeur b2 dans un Derived * en utilisant dynamic_cast
    // 5 bis. Afficher le résultat de l'opération et constater
    ...................................;
    ...................................;
    ...................................;
    ...................................;
    
    // destructions
    delete b1; b1 = nullptr;
    delete b2; b2 = nullptr;
    
    return 0;
}
