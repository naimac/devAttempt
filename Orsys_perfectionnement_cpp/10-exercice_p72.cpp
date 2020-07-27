#include <iostream>

class Point
{
public:
	Point(double i, double j) : _x(i), _y(j)
	{
	}

	Point(const Point &p) : _x(p.GetX()), _y(p.GetY())
	{
	}

	~Point()
	{
	}

	double GetX() const
	{
		return this->_x;
	}

	double GetY() const
	{
		return this->_y;
	}

	void SetX(double i) // implicitement inline
	{
		this->_x = i;
	}

	void SetY(double j)
	{
		this->_y = j;
	}

private:
	mutable double _x;
	mutable double _y;
};

//.cpp
// inline void Point::setX(double xx) // explicit inline
// {

// }

class Segment
{
public:
	explicit Segment(const Point &pp1, const Point &pp2) : _pP1(new Point(pp1)),
														   _pP2(new Point(pp2))
	{
	}

	explicit Segment(const Segment& p)// Segement S2(S1)
	{
		// &S2 == this
		_pP1 = new Point(*p._pP1);
		_pP2 = new Point(*p._pP2);
	}

	Segment &operator=(const Segment &s)
	{
		if (this == &s)
		{
			return *this;
		}

		// on peut aussi faire
		// delete p1;
		// p1 = new Point(*seg.p1);
		// delete p2;
		// p2 = new Point(*seg.p2);

		*_pP1 = *s._pP1;
		*_pP2 = *s._pP2;

		// this->_pP1 = s.GetPP1();
		// this->_pP2 = s.GetPP2();
		return *this;
	}

	~Segment()
	{
		delete _pP1; delete _pP2;
		_pP1 = _pP2 = nullptr;
	}

	// surcharge operateur =

private:
	Point *_pP1 = nullptr;
	Point *_pP2 = nullptr;
};

int main()
{
	Point PP1(0.0, 1.7), PP2(1.2, 5.6);
	Point PP3(3.0, 1.8), PP4(9.2, 3.6);
	Segment S1(PP1, PP2);
	Segment S2(S1); // Appel du constructeur par copie Segment S3( PP3, PP4 );
	Segment S3( PP3, PP4 );
	S3 = S1;		// Affectation

	return 0;
}