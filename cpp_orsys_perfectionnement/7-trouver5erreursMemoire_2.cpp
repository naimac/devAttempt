#include <iostream>
#include <memory>

classe PileInt
{
	int *TabInt; // erreur doit etre init a nullptr
	short NbrInt; // idem

public:
	// PileInt() : NbrInt(0) {} // erreur
	PileInt() : NbrInt(0), TabInt(NULL) {} // bonne pratique
	virtual ~PileInt() {
		// manque un delete[] TabInt;
		// TabInt = NULL;
	}
	void Push(int);
	int Pop();
	short GetNbr() const;
	void PrintPile() const;
};

void  PileInt::Push(int i)
{
	if (TabInt == NULL)
	{
		TabInt = new int[1];
	}
	else
	{
		int * Temp = new int [NbrInt + 1];
		memcpy( Temp, TabInt, NbrInt * sizeof(int));
		// manque delete[] TabInt;
		TabInt = Temp;
	}
	TabInt[NbrInt++];
}

int PileInt::Pop()
{
	if (NbrInt > 0)
	{
		int Ret = TabInt[ NbrInt-- ]; // faut mettre le -- devant et pas apres
		return Ret;
	}
	else
	{
		return -9999;
	}
}

short PileInt::GetNbr()
{
	return NbrInt;
}

void PileInt::PrintPile()
{
	for (int t; t <= NbrInt; t++) // < et pas <=
	{
		std::cout << "Element [" << t << "] -> " << TabInt[t] << std::endl;
	}
}

int main()
{
	PileInt Pile1;

	Pile1.push(1);
	Pile1.push(2);
	Pile1.push(3);
	Pile1.push(4);
	Pile1.push(5);

	Pile1.PrintPile();

	std::cout << Pile1.pop() << std::endl;
	std::cout << Pile1.pop() << std::endl;
	std::cout << Pile1.pop() << std::endl;
	std::cout << Pile1.pop() << std::endl;
	std::cout << Pile1.pop() << std::endl;

	Pile1.PrintPile();

	Pile1.push(10);
	Pile1.push(20);
	Pile1.push(30);
	Pile1.push(40);
	Pile1.push(50);

	Pile1.Pop();

	Pile1.PrintPile();

	return 0;
}