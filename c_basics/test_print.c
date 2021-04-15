#include <stdio.h>

int a()
{
	printf("a\n");
	return 0;
}

int b()
{
	printf("b\n");
	return 0;
}

int main ()
{
	if (a() | b())
	{
		printf("main\n");
	}
	return 0;
}
