//
//  main.cpp
//  LTMtypeid
#include <iostream>
#include <string>
#include <typeinfo>

struct Base {}; // non-polymorphique
struct Derived : Base {};

struct Base2 { virtual void method() {} }; // polymorphique
struct Derived2 : Base2 {};

int main() {
    int i = 50;
    std::string s = "string";
    double * pd = nullptr;
    
    std::cout << "type de i: " << typeid(i).name() << std::endl
    << "type de s: " << typeid(s).name() << std::endl
    << "type de pd: " << typeid(pd).name() << std::endl;
    
    // Non-polymorphique évaluation ,type statique
    Derived d1;
    Base& b1 = d1;
    std::cout << "Classe de base non polymorphique: " << typeid(b1).name() << '\n';
    
    // Polymorphique
    Derived2 d2;
    Base2& b2 = d2;
    std::cout << "Classe de base polymorphique: " << typeid(b2).name() << '\n';
    
    try {
        // lancement d'une exception ci-dessous
        Derived2 * ptr = nullptr;
        std::cout << typeid(*ptr).name() << '\n';
    
    } catch (const std::bad_typeid& er) { // exception
        std::cout << " catch " << er.what() << '\n';
    }
}
