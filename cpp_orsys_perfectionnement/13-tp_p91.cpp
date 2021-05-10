#include <iostream>
#include <memory>

// X x();

// un smart pointer prend un new et pas un un element declare sur la stack
// smart pointer fait un delete et il peut pas faire un delete sur un element declare sur la stack

class X{
};

int main()
{
    // Créez un objet sp1 (shared_ptr) pointant une instance de X allouée sur le tas
    std::shared_ptr<X> sp1(new X());

    // Quel est l'état du compteur de référence ?
    int count1 = sp1->use_count();

    // Créez un objet sp2 (shared_ptr) pointant la même instance que ci-dessus
    std::shared_ptr<X> sp2(sp1);

    // Etat du compteur de sp2 ?
    int count2 = sp2->use_count();

    // Créez un objet sp3 par défaut et utilisez l'opérateur = pour lui affecter l'instance ci-dessus
    std::shared_ptr<X> sp3; // pas de parentheses
    sp3 = sp1;

    // Etat du compteur de sp3 ?
    // Afficher avec std::cout l'état du compteur de sp3
    std::cout << sp3->use_count() << std::endl;

    // Utilisez la méthode reset() sur sp3
    sp3->reset();

    // utilisez l'opérateur ! pour constater l'état de sp3
    if (..............)
    {
        std::cout << "sp3 KO" << std::endl;
    }

    std::cout << "sp3.count = " << sp3.use_count() << std::endl;
    std::cout << "sp2.count = " << sp2.use_count() << std::endl;

    sp1.reset();
    sp2.reset();
    sp3.reset();

    // Créez un smart pointeur sp6 (weak_ptr)
    ...........................;

    std::cout << sp6.use_count() << std::endl; // Ici le compteur est à 2

    return 0;
}