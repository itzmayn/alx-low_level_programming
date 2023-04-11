#include <stdio.h>

int main(int argc, char *argv[]) /* Print all arguments */
{
	int i = 0;

	while (argv[i] || i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	return 0;
}
