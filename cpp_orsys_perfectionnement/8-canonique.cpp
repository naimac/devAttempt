#include <iostream>

class Point
{
private:
	double x;
	double y;

public:
	// Point() : x(0), y(0.0) {}

	//permet d'instancier si aucun parametre passee parce qu'on a des parametres par defaut
	Point(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) {}
	// Point& operator = {const Point &}; // le fait automatiquement
	virtual ~Point() {}
};

// construction --> l'objet existe pas avant

class Segment
{
private:
	Point *p1, *p2;
	Segment(const Segment &); //c++98

	Segment(const Segment &) = delete; // empecher copie en cpp11 // s1(s2) --> s1 existe pas avant que je cree
	// on peut aussi creer Point &p1, &p2

	Segment& operator=(const Segement& ) = delete; // pas de construction pas d'affectation

public:

// instance interieur a objet doivent etre cree avant que objet existe
// donc on utilise la liste initialisation
	// TOUJOURS A PASSER PAR REFERENCE
	// Segment( const Point& pp1, const Point& pp2 : p1(pp1), p2(pp2) {
	// }

	Segment( const Point& pp1, const Point& pp2 ) : 
						p1(new Point(pp1)), 
						p2(new Point(pp2)) {
	}

	~Segment() {
		delete p1; delete p2;
		// on ne fait pas delete p1, p2 !!!
		p1 = p2 = NULL; // ok
	}
};

int
main()
{
	// Point p1;
	// Point p2(4.5, 9.0);

	// construction anonyme
	Segment s1( Point(5.6, 8.9), Point(3.6, 7.0) );
	Segment s2(s1); // copie [construction]

	// CI DESSOUS NE PAS FAIRE !!!
	Segment s3 = s1; // copy constructor implicit [construction]

	s1 = s4; // operateur =

	return 0;
}