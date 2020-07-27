//
//  main.cpp
//  LTMLambda
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Echelle {
public:
    explicit Echelle(int echelle) : _echelle(echelle) {}
    
    void appliquer(vector<int>& v) const {
        for_each(v.begin(), v.end(), [this](int&i) { i *= _echelle; });
    }
private:
    int _echelle;
};

int main(int argc, const char * argv[])
{
    
    auto pf = [](){};
    
    int f = 0;
    int i = 1;
    
    auto g = [=] () {
        f++;
        i++;
        return --i;
    };
    
    int r = g();

    
    
    
    
    auto p = [] () { std::cout << "Je suis une fonction lambda" << std::endl;};
    p(); // Appel de la fonction
    
    
    
    
    
    auto ajouter = [] (int aa, int bb) -> int { return aa + bb; };
    int ret = ajouter(1,2);
    
    
    
    
    
    int a = 2, a1 = 3, a2 = 4;
    auto p2 = [&] () { a1++; a2++; return a*a; }; // [&a, &a1, &a2]
    std::cout << p2() << " " << a1 << " " << a2 << std::endl; // Appel de la fonction
    
    
    
    
    
    
    // ci-dessous mutable obligatoire
    auto p3 = [=] () mutable { a1++; a2++; return a*a; };
    std::cout << p3() << " " << a1 << " " << a2 << std::endl;
    
    
    
    
    
    // Expression lambda avec passage de paramètres
    int n = [] (int x, int y) { return x + y; }(6, 5);
    cout << n << endl; // ??
    
    
    
    
    
    
    
    
    
    
    // Expression Lambda imbriquée, mauvaise pratique !
    int r1 = [](int x) { return [](int y) { return y * 2; }(x) + 6; }(9);
    cout << r1 << endl; // ???
    
    
    
    
    
    
    
    
    
    
    
    
    // autre exemple
    std::vector<int> tab { 1,2,3,4,5,6,7 };
    int x = 6;
    tab.erase(std::remove_if(tab.begin(), tab.end(), [&x](int n) { return n < x; } ), tab.end());
    std::cout << std::endl;
    
    // autre exemple encore
    std::vector<int> tab2 { 21,-12,33,14,-55,-16,17 };
    sort( tab2.begin(), tab2.end(), [](int a, int b) { return abs(a) < abs(b);});
    
    
    
    
    
    
    // 1.
    int aa = 2;
    int bb = 3;
    
    auto ajouter2 = [&] (int c)  { return c + aa + bb; };
    std::cout << ajouter2(2) << std::endl;
    
    
    
    
    
    
    
    // 2. Créer une liste d'entier
    std::list<int> nombres;
    nombres.push_back(13);
    nombres.push_back(18);
    nombres.push_back(45);
    nombres.push_back(49);
    nombres.push_back(97);
    
    // Utilisation de la find_if fonction
    const list<int>::const_iterator result =
        find_if(nombres.begin(), nombres.end(), [](int n) { return (n % 2) == 0; });
    
    // Impression du résultat
    if (result != nombres.end()) {
        cout << "Le premier élément pair est : " << *result << "." << endl; // ???
    } else {
        cout << "La liste ne contient pas de nombres pairs." << endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    // 3. Appliquer une échelle à un tableau de valeurs
    vector<int> values;
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    values.push_back(5);
    
    Echelle e1(3);
    e1.appliquer(values);
    
    return 0;
}

