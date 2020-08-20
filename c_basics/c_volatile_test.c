#include <stdio.h>

int main()
{
	// pointer basic
	const int a1 = 3;
	printf("after (const int a1 = 3) --> a1 = [%d]\n", a1);

	int *b1 = (int *)&a1;
	printf("after (int *b1 = &a1) --> a1 = [%d], b1 = [%d]\n", a1);

	*b1 = 2;
	printf("after (*b1 = 2) --> a1 = [%d]\n", a1);

	// tentative volatile en c

	printf("\n");
	volatile const int a2 = 3;
	printf("after (volatile const int a2 = 3) --> a2 = [%d]\n", a2);

	int *b2 = (int*)&a2;
	printf("after (int *b2 = (int *)&a2) --> a2 = [%d]\n", a2);

	*b2 = 2;
	printf("after (*b2 = 2) --> a2 = [%d]\n", a2);

	return 0;
}
