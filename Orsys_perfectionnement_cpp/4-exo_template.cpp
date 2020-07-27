#include <iostream>
#include <string>
#include "4-exo_template.hpp"

using namespace std;

int main()
{
	Tableau<int> TableauEntier(10);
	TableauEntier[0] = 0;
	TableauEntier[1] = 1;
	TableauEntier[2] = 2;
	TableauEntier[3] = 3;
	TableauEntier[4] = 4;
	TableauEntier[5] = 5;

	for (int t = 0; t < 6; t++)
		cout << "TableauEntier[" << t << "] = " << TableauEntier[t] << endl;

	// String ...
	Tableau<string> TableauChaine(100);

	for (int t = 0; t < 6; t++)
	{
		TableauChaine[t] = "Toto";
	}

	for (int t = 0; t < 6; t++)
	{
		cout << "TableauChaine[" << t << "] = " << TableauChaine[t] << endl;
	}

	return 0;
}