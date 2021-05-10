#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

// 3. Utilisez une expression lambda avec un for_each( .... )
class Echelle
{
public:
    // constructeur à définir
    Echelle(int i) : _echelle(i) {}; // javais pas mis _echelle(echelle)
    virtual ~Echelle(){};

    void appliquer(std::vector<int> values) const
    {
        // Utilisez le for_each pour appliquer une échelle
        // sur chaque élément du tableau
        std::for_each(values.begin(), values.end(), [this](int &val){val *= _echelle;});
        // moi j'ai mis & au lieu du this
    }

private:
    int _echelle;
};

int main()
{

    // 1. Créez une expression lambda qui prend un paramètre (int)
    // et qui ajoute param_de_la_fonction + aa + bb
    int aa = 2;
    int bb = 3;

    auto ajouter2 = [&](int cc) -> int { return (aa + bb + cc); };
    std::cout << ajouter2(2) << std::endl;

    // 2. Grâce à la fonction std::find_if( ........, .........., ...... ),
    // trouvez le premier nombre pair

    std::list<int> nombres;
    nombres.push_back(13);
    nombres.push_back(18);
    nombres.push_back(45);
    nombres.push_back(50);
    nombres.push_back(97);

    // Utilisation de la find_if fonction
    // jai completmnet zappe de faire std::list<int>::const_iterator , c est ecrit dans la doc que ca renvoie un iterator
    const std::list<int>::const_iterator result = std::find_if(nombres.begin(), nombres.end(), [&](int val) { return (val % 2) == 0; });

    std::vector<int> values; // vecteur de valeurs
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    values.push_back(5); // etc...

    Echelle e1(3); // coefficient à appliquer
    e1.appliquer(values);
}