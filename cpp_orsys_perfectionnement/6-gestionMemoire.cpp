#include <iostream>

class X
{
private:
public:
	X()
	{
		std::cout << "X::X()" << std::endl;
	};

	~X()
	{
		std::cout << "X::~X()" << std::endl;
	}

	void method() {}
};

void foo();
void Termine();

X xg; // zone globale
X * pg = nullptr; // zone globale

int main() // thread
{
	X *p = new X();

	pg = new X(); // initialiser
	atexit(Termine); // pratique pour nettoyer le code quand on a pas la main sur le Main

	X x1; // pile
	::xg.method(); // syntaxe pour appeler une globale n'appartient aucune classe 5-	

	x1.method();

	delete p;
	p = nullptr;

	return 0;
}

void Termine()
{
	delete pg;
	pg = NULL;
}

void foo()
{
	X tab[4];

	pg = new X(); // initialiser

	// pile pointe vers le tas (stack)
	X** dp = new X * [5]; // tableau de pointeurs 

	dp[0] = new X;

	{
		X x5;
		static X x6; // cree au premier passage de foo // detruit quand on termine le main
	}

	delete dp[0]; // d'abord
	delete [] dp; // ensuite
}