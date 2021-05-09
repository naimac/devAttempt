#include <iostream>
using namespace std;

int main()
{
	int i = 2;
	int *pi = &i;
	int **dpi = &pi; // double pointeur == pointeur indirect
	//
	cout << "Afficher le contenu de i avec i : ";
	cout << i << endl;
	//
	cout << "Afficher le contenu de i avec pi : ";
	cout << *pi << endl;
	
	cout << "Afficher le contenu de i avec dpi : "; // erreur
	cout << **dpi << endl;
	
	cout << "Afficher l’adresse de i avec pi : "; // erreur
	cout << *pi << endl;
	//
	cout << "Afficher l’adresse de pi avec dpi : ";
	cout << dpi << endl;
	//
	cout << "Afficher l’adresse de i avec dpi : ";
	cout << *dpi <<endl;

	return 0;
}