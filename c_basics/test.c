#include <stdio.h>

char *chercheCarac(char *chaine, char c)
{
	int i = 0;
	if (chaine == NULL)
		return NULL;

	while (*(chaine + i))
	{
		if (chaine[i] == c)
		{
			return (chaine + i);
		}
		i++;
	}
	return NULL;
}

double moyenne (int *ptab, int n)
{
	double res = 0.0;
	int sum = 0;
	int i = 0;

	if (n == 0)
		return res;

	while (ptab && i < n)
	{
		sum += ptab[i];
		i++;
	}
	res =  sum / n;
	return (res);
}

int main(void)
{
	int ptab[2] = {4, 4};
	double val = moyenne(ptab, 2);
	printf("moyenne = %lf\n", val);

	char *str = "rocade";
	char *res = chercheCarac(str, 'c');

	printf("strFound = %s\n", res);

	return 0;
}
