#include <iostream>
#include <memory>

classe PileInt
{
	int *TabInt;
	short NbrInt;

public:
	PileInt() : NbrInt(0) {}
	virtual ~PileInt() {}
	void Push(int);
	int Pop();
	short GetNbr() const;
	void PrintPile() const;
}