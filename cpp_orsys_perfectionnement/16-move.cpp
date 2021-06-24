#include <iostream>
#include <algorithm>

using namespace std;

//Créez la classe Segment tel que :

class Point
{
public:
    double x = 0.0;
    double y = 0.0;
    Point(double xx, double yy) : x(xx), y(yy) {}
    Point(const Point &) = default;
};

class Segment
{
private:
    Point *p1, *p2;

public:
    Segment(const Point &pp1, const Point &pp2) : p1(new Point(pp1)), p2(new Point(pp2))
    {
    }

    // constructeur par copie
    Segment(const Segment &cs)
    {
        p1 = new Point(*cs.p1);
        p2 = new Point(*cs.p2);

        // *p1 = *cs.p1;
        // *p2 = *cs.p2;
    }

    // move constructor
    Segment(Segment &&cs)
    {
        p1 = cs.p1;
        cs.p1 = nullptr;

        p2 = cs.p2;
        cs.p2 = nullptr;
    }

    Segment& operator=(Segment &cs)
    {
        if (&cs == this)
        {
            return *this;
        }

        p1 = cs.p1;
        cs.p1 = nullptr;
        p2 = cs.p2;
        cs.p2 = nullptr;

        return *this;
    }

    // move operator =
    Segment& operator=(Segment &&cs)
    {
        p1 = cs.p1;
        p1 = nullptr;

        p2 = cs.p2;
        p2 = nullptr;

        return *this;
    }

    // Le segment retourne son clone
    Segment clone()
    {
        return (std::move(*this));
    }

    void printAddress()
    {
        cout << "objet = " << this << ", p1 = " << p1 << ", p2 = " << p2 << endl;
    }

    ~Segment()
    {
        if (p1)
        {
            delete p1;
            p1 = nullptr;
        }
        if (p2)
        {
            delete p2;
            p2 = nullptr;
        }
    }
};

// Implémentez pour la classe Segment : le constructeur de copie et l'opérateur = de copie
// Implémentez pour la classe Segment : le constructeur et l'opérateur de move
// Observez le passage dans les mécanismes implémentés

int main()
{
    //case 1
    Segment s1(Point(1.2, 3.4), Point(3.4, 8.9));

    // assertion vérifiant que s1 est correct
    s1.printAddress();

    // case 2
    Segment s2(s1);
    // Segment s4 = s1;
    s2.printAddress();

    // case 3 operator fonctionnement de base
    s1 = s2; // appel operator = de copie

    // case 4 : test du std::move sur l'affectation
    s1 = std::move(s2); // call move operator =
    // assertion: s1 <- s2, s2 invalide

    Segment s3(std::move(s1)); // move ctor
    s3.printAddress();

    s2 = s3.clone();                                // call move operator =
    s2 = Segment(Point(1.2, 3.4), Point(3.4, 8.9)); // call move operator =

    return 0;
}