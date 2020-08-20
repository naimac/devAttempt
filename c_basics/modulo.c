#include <stdio.h>

int main()
{
	float a = 5.0;
	float b = 2.0;
	int c = 5;
	int d = 2;

	printf("a = %f\nb = %f\nc = %d\nd = %d\n\n", a, b, c, d);
	printf("a/b = %f\na/d = %f\nc/b = %f\nc/d = %d\n", a/b, a/d, c/b, c/d);

	return 0;
}