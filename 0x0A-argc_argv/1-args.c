#include <stdio.h>

int main(int argc, char *argv[]) /* Print the number of arguments */
{
	if (argv[0])
	{
		int length = argc - 1;

		printf("%d\n", length);
	}

	return 0;
}
