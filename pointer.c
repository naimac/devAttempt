#include <stdio.h>

int main()
{
	int i = 1;
	int *j = &i;

	*j = 3;

	printf("i = %d\n", i);
	printf("addr i = %p\n", &i);
	printf("addr j = %p\n", j);
	printf("addr i = %d\n", i);
	printf("addr &(*j) = %p\n", &(*j));
	printf("*j = %d\n", *j);

	return 0;
}
