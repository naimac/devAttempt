#include <iostream>

int main()
{
	int i = 2;
	int j = &i;
	int *k = &i;
	int **l = &k;

	std::cout << "i = " << << std::endl;

	return 0;
}