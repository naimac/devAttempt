#include <iostream>

class Point {
public:
    inline double GetY() const;
    inline double GetX() const;
    inline void SetY( double );
    inline void SetX( double );
    
    explicit Point( double = 0.0, double = 0.0 );
    
    Point( const Point& ) = default;
    virtual ~Point();
 private:
    double y;
    double x;
};

// CPP
Point::Point( double xx, double yy ) : x( xx ), y( yy ) {}
Point::~Point() {}

void Point::SetX( double xx ) {
    x = xx;
}

void Point::SetY( double yy ) {
    y = yy;
}

double Point::GetX() const {
    return x;
}

double Point::GetY() const {
    return y;
}

//
// header
class Segment {
private:
    Point * _pP1 = nullptr, * _pP2 = nullptr; // c+11
    
public:
// explicit pour eviter construction avec '='
// que devant les constructeur
    explicit Segment( const Point&, const Point& );
    
    explicit Segment( const Segment& ); // copy ctor
    Segment& operator =( const Segment& ); // déclaration
    
    virtual ~Segment();
};

Segment::Segment( const Point& P1, const Point& P2 ) :
        _pP1(new Point( P1 )),
        _pP2(new Point( P2 ))
{}

// copy ctor
Segment::Segment(const Segment& s) { // Segment S2( S1 );
    _pP1 = new Point( *s._pP1 );
    _pP2 = new Point( *s._pP2 );
}

Segment::~Segment() {
    delete _pP1; _pP1 = nullptr;
    delete _pP2; _pP2 = nullptr;
}

// S3 = (S4 = S1); Implémentation
Segment& Segment::operator =( const Segment& CT ) {
    if( this != &CT ) {
        /*if(pP1 != NULL ) delete pP1;
         if(pP2 != NULL ) delete pP2;
         
         pP1 = new Point(*CT.pP1);
         pP2 = new Point(*CT.pP2);*/
        
        *_pP1 = *(CT._pP1);
        *_pP2 = *(CT._pP2);
    }
    
    return *this;
}

////////
int main() {
    {
        Point PP1( 0.0F, 1.7F ), PP2( 1.2F, 5.6F );
        Point PP3( 3.0F, 1.8F ), PP4( 9.2F, 3.6F );
        
        Segment S1( PP1, Point( 1.2F, 5.6F ) );

        // Appel du constructeur par copie
        Segment S2( S1 );
        //Segment S5 = S1; // KO car constructeur explicit

        Segment S3( PP3, PP4 ); // constructeur surcharge

        // Affectation
        //S3 = S4;
        S3 = S1 = S2; // S3.operator =( S1.operator =( S2 ) );
    }
    // ::__CrtDumpMemoryLeaks();
    
    return 0;
}




















