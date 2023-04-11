#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) /* Multiply two numbers */
{
	int r;

	if (argc == 3)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

		r = a * b;
		printf("%d\n", r);
	}
	else
	{
		printf("Error\n");
		return 1;
	}

	return 0;
}
