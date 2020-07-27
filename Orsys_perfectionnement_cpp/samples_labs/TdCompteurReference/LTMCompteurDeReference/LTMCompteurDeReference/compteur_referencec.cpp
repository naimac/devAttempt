#include <iostream>

// Declaration
class Point {
public:
	explicit Point( double = 0.0, double = 0.0 );
	double x, y;
};

// Implementation
Point::Point( double xx, double yy ) : x( xx ), y( yy ) {}

// Declaration
class Shape {
public:
	explicit Shape() {}
	virtual ~Shape() {}
    virtual void draw() = 0;
};

// Declaration
class Circle : public Shape {
private:
	Point * _pCentre;
	double _rayon;
public:
	explicit Circle( Point&, double = 0.0 );
	~Circle();
    virtual void draw() {
        std::cout << "draw()" << std::endl;
    }
};

// Implementation
Circle::Circle( Point& centre, double rayon ) : _rayon( rayon ) {
	_pCentre = new Point( centre );
}

Circle::~Circle() {
	if( _pCentre ) {
		delete _pCentre;
        _pCentre = NULL;
    }
}

// SmartPointer pour le Cercle : Circle_var
class Circle_var {
private:
	struct Value {
		int _refCount;
		Circle * _pCircle;

		Value( Circle * );
		~Value();
	};
	
	Value * _pValue;
public:
	Circle_var( Circle * = NULL );
	
	// Constructeur par copie
	Circle_var( const Circle_var & );
	
	// Surcharge de l'operateur =
	Circle_var& operator = ( const Circle_var& );

	virtual ~Circle_var();
	Circle * operator ->() const;
	Circle & operator *() const;
};

// ImplŽmentation de la classe imbriquŽe
Circle_var::Value::Value( Circle * p ) : _refCount( 1 ) {
	_pCircle = p;	
}

Circle_var::Value::~Value() {
	if( _pCircle ) {
		delete _pCircle;
        _pCircle = NULL;
    }
}

// ImplŽmentation
Circle_var::Circle_var( Circle * p ) : _pValue( new Value( p ) ) {
}

Circle_var::Circle_var( const Circle_var & rc ) : _pValue( rc._pValue ) {
	(_pValue->_refCount)++;
}

Circle_var& Circle_var::operator = ( const Circle_var&  c ) {

	// Test de l'affectation de l'objet sur lui-meme
	if( this == &c )
		return *this;

	// Autre test important, s'il rŽfŽrence dŽjˆ alors ne rien faire !
	if( _pValue == c._pValue )
		return *this;

	// ici destruction de l'instance de l'objet rŽfŽrence dans le cas ou le
	// compteur de rŽfŽrence est ˆ 1
	if( --_pValue->_refCount == 0 ) {
		delete _pValue;
        _pValue = NULL;
    }

	// On recupere le pointeur entrant !
	_pValue = c._pValue;
	_pValue->_refCount++;

	return *this;
}

Circle_var::~Circle_var() {
	if( --(_pValue->_refCount) == 0 ) {
		delete _pValue;
        _pValue = NULL;
    }
}

Circle * Circle_var::operator ->() const {
	return _pValue->_pCircle;
}

Circle& Circle_var::operator *() const {
	return *(_pValue->_pCircle);
}

//
int main() {
	Point P1( 0.1, 0.2 );
	double R = 101.0;

	// Creation d'une instance
	Circle_var smp (new Circle( P1, R ));

	// Appel du constructeur par copie
	Circle_var smp2( smp );

	// Declaration d'un Smart Point -> NULL !
	Circle_var smp3( new Circle(P1,R) );

	// Appel de l'operateur =
	smp3 = smp;
    
    // call
    smp3->draw();
    (*smp3).draw();
    
    return 0;
}
