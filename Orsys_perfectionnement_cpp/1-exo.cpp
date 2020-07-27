#include <stdlib.h>

class X
{
public:
	X() {}
	virtual ~X() {}
	void Methode() {}
};

int main()
{
	X tabX[10][5];
	X *px = NULL;

	// Initialiser le pointeur sur le premier élément du tableau
	px = &tabX[0][0];

	// Trouver 3 solutions pour que chaque instance de "tabX"
	// appelle sa méthode "Methode" avec le pointeur px

	//solution 1
	for (int t = 0; t < 50; t++)
	{
		(*(px + t).Methode());
	}

	// solution 2
	for (int t = 0; t < 50; t++)
	{
		(px + t)->Methode();
	}

	// solution 3
	for (int t = 0; t < 50; t++)
	{
		px[t].Methode();
	}

	return 0;
}