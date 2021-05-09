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

class A : virtual public Object {
public:
    A() {}
    ~A() {}
};

class B : public virtual Object {
public:
    B() {}
    ~B() {}
};

class D : public A, public B {
public:
    D() {}
    ~D() {}
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
    virtual ~Derived() {}
    virtual void name() {}
};

int main()
{
    // Soit les allocations suivantes ...
    D d;
    A * pa = &d; // upcasting
    
    // 1. Caster le pointeur pa dans un D* en utilisant dynamic_cast
    // 1 bis. Afficher le résultat de l'opération et constater
    D *d1 = dynamic_cast<D *>(pa);
    if (d1)
    {
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }
    
    // 2. Caster le pointeur pa dans un B* en utilisant dynamic_cast
    // 2 bis. Afficher le résultat de l'opération et constater
    B *b = dynamic_cast<B *>(pa);
    if (b)
    {
        std::cout << "success" << std::endl;
    }
    else
    {
        std::cout << "failure" << std::endl;
    }
    
    B b3;
    // 3. Caster b3 (son adresse) dans un A* en utilisant dynamic_cast
    // 3 bis. Afficher le résultat de l'opération et constater
    A *a = dynamic_cast<A *>(&b3);
    if (a)
    {
        std::cout << "a success" << std::endl;
    }
    else
    {
        std::cout << "a failure" << std::endl;
    }
    
    Base * b1 = new Base();
    // 4. Caster le pointeur b1 dans un Derived * en utilisant dynamic_cast
    // 4 bis. Afficher le résultat de l'opération et constater
    Derived *x = dynamic_cast<Derived *>(b1);

    if (x)
    {
        std::cout << "x downcast ok" << std::endl;
        x->name(); // ok
    }
    else
    {
        std::cout << "x failure" << std::endl;
    }
    
    Base * b2 = new Derived();
    // 5. Caster le pointeur b2 dans un Derived * en utilisant dynamic_cast
    // 5 bis. Afficher le résultat de l'opération et constater
    Derived *y = dynamic_cast<Derived *>(b2);
    if (y)
    {
        std::cout << "y success" << std::endl;
    }
    else
    {
        y->name(); // ok
        std::cout << "y failure" << std::endl;
    }
    
    // destructions
    delete b1; b1 = nullptr;
    delete b2; b2 = nullptr;
    
    return 0;
}
