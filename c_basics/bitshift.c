#include <stdio.h>
#include <string.h>

int main()
{
	char *s = strdup("1234");
	printf("valuei before [%s]\n", s);

	*s >>= 2;

	printf("value after [%s]\n", s);

	int a = 2;

	printf("a = 2; a << 1 = %d\n", a << 1);

	return 0;
}
