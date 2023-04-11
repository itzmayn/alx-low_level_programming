#include <stdio.h>
#include <stdlib.h>

int _isdigit(int c) /* Check if character is a digit */
{
	return (c > 47 && c < 58) ? 1 : 0;
}

int main(int argc, char *argv[]) /* Sum positive numbers */
{
	unsigned int r = 0;
	int i = 1;

	if (argc == 1)
	{
		printf("0\n");
		return 0;
	}

	while (i < argc)
	{
		int j = 0;

		while (argv[i][j])
		{
			if (_isdigit(argv[i][j]) == 0)
			{
				printf("Error\n");
				return 1;
			}
			j++;
		}

		r += atoi(argv[i]);
		i++;
	}

	printf("%d\n", r);
	return 0;
}
