#include <iostream.h>

// Déclaration
class CATPoint {
public:
	CATPoint( double = 0.0, double = 0.0 );
	double x, y;
};

// Implémentation
CATPoint::CATPoint( double xx, double yy ) : x( xx ), y( yy ) {
}

// DÈclaration
class CATShape {
public:
	CATShape() {}
	virtual ~CATShape() {}
};

// DÈclaration
class CATCircle : public CATShape {
private:
	CATPoint * _pCentre;
	double _rayon;
public:
	CATCircle( CATPoint&, double = 0.0 );
	~CATCircle();
};

// ImplÈmentation
CATCircle::CATCircle( CATPoint& Centre, double Rayon ) : _rayon( Rayon ) {
	_pCentre = new CATPoint( Centre );
}

CATCircle::~CATCircle() {
	if( _pCentre )
		delete _pCentre;
}

// SmartPointer pour le Cercle : CATCircle_var
class CATCircle_var {
private:
	// ...

public:
	CATCircle_var( CATCircle * = NULL );
	
	// ImplÈmenter le constructeur par copie
	...................................;
	
	// Surcharge de l'opÈrateur =
	...................................;

	virtual ~CATCircle_var();
	CATCircle * operator ->() const;
	CATCircle * operator *() const;
};

// ImplÈmentations ici ‡ prÈvoir ...


// Exemple de main
void main() {
	CATPoint P1( 0.1, 0.2 );
	double R = 101.0;

	// Création d'une instance
	CATCircle_var smp( new CATCircle( P1, R ) );

	// Appel du constructeur par copie
	CATCircle_var smp2( smp );

	// Déclaration d'un Smart Point -> NULL !
	CATCircle_var smp3;

	// Appel de l'opérateur =
	smp3 = smp;
}
