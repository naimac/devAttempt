#include <iostream>

class Figure
{
public:
	Figure() { std::cout << "Figure::Figure()" << std::endl; }
	virtual ~Figure() { std::cout << "Figure::~Figure()" << std::endl; }
};

class Rectangle : public Figure
{
public:
	Rectangle() { std::cout << "Rectangle::Rectangle()" << std::endl; }
	~Rectangle() { std::cout << "Rectangle::~Rectangle()" << std::endl; }
};

int main()
{
	// Figure *pf = new Rectangle();
	Figure pf2 = Rectangle();
	// delete pf;
	// pf = nullptr;
	return 0;
}