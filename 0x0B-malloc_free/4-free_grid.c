#include "main.h"

/**
* free_grid - frees a 2d array
* @grid: memory block to be freed
* @height: height of the array
* Return: void
*/
void free_grid(int **grid, int height)
{
	if (grid == NULL)
		return;

	for (int i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
