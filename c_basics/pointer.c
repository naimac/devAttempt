#include <stdio.h>

int main()
{
	int i = 2;
	int *pi = &i;
	int **dpi = &pi; // double pointeur == pointeur indirect

	printf("int i = 2\nint *pi = &i\nint **dpi = &pi\n");

	printf("Afficher le contenu de i  avec   i : %d\n", i);

	printf("Afficher le contenu de i  avec  pi : %d\n", *pi);
	
	printf("Afficher le contenu de i  avec dpi : %d\n", **dpi);
	
	printf("Afficher l’adresse de  i  avec  pi : %d\n", pi);

	printf("Afficher l’adresse de  pi avec dpi : %p\n", dpi);

	printf("Afficher l’adresse de  i  avec dpi : %p\n", *dpi);

	return 0;
}