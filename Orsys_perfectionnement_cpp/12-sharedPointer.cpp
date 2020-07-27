#include <iostream>
#include <memory>

class X
{
};

int main()
{
	std::shared_ptr<X> sp1( new X() ); 
	// va detruire le X en passant par le return
	// vu que sp1 est cree sur la pile

	return 0;
}

void fonction (std::shared_ptr<X> sp) // on passe par copie
{
	// ...
	// compteur a 2
}