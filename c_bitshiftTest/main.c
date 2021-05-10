#include <stdio.h>
#include <string.h>

int main()
{
	char *s = strdup("1234");
	printf("valuei before [%s]\n", s);

	*s >>= 2;

	printf("value after [%s]\n", s);
	return 0;
}
