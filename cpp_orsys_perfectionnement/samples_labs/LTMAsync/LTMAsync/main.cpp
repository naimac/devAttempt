//
//  main.cpp
//  LTMAsync
//
#include <iostream>
#include <future> // std::async, std::future

using namespace std;

// vérifie s'il s'agit d'un nombre premier
bool is_prime (long x) {
    for ( long i = 2; i < x; ++i ) {
        if ( x%i == 0 )
            return false;
    }
    return true;
}

long fib( long n ) {
    if (n < 2) {
        return n;
    } else
        return fib(n-1) + fib(n-2);
}

int main () {
    // Appel asynchrone 1
    const long nombre = 31232232354343;
    std::future<bool> fut = std::async( is_prime, nombre );
    cout << "\nrecherche en cours.\n";
    //.... autres taches
    bool ret = fut.get();  // attendre
    if (ret)
        cout << nombre << " est un nombre premier !\n";
    else
        cout << nombre << " n'est pas un nombre premier.\n";
    
    // 50 premiers nombres premiers
    cout << "\nNombres premiers :" << endl;
    for( long t = 0; t < 50; t++ ) {
        if ( is_prime(t) ) {
            cout << t << ", ";
        }
    }
    
//    cout << "\nListe de fibonacci :" << endl;
//    //fibonacci jusque 30
//    for( int t = 0; t < 45; t++ ) {
//        cout << fib(t) << ", ";
//    }
//    cout << endl;
    
    // Appel asynchrone
    const long n1 = 43, n2 = 44;
    std::future<long> resultat1 = std::async( fib, n1 );
    std::future<long> resultat2 = std::async( fib, n2 );
    
    cout << "\nrecherche des éléments de la liste n° " << n1 << " et " << n2 <<endl;
    cout << "résultat pour " << n1 << " = " << resultat1.get() << endl;
    cout << "résultat pour " << n2 << " = " << resultat2.get() << endl;
    cout << "fini" << endl;
    // Appel asynchrone 2
//    std::future<int> a2 ( std::async( [](int m, int n) { return m + n;} , 2, 5) );
//    std::cout << a2.get() << std::endl;
//    
//    int a = 1, b = 2;
//    auto p = [=]() -> int { return a + b; };
//    std::future<int> a3( std::async( [=]() -> int { return a + b; } ) );
//    std::cout << a3.get() << std::endl;
    
    return 0;
}








