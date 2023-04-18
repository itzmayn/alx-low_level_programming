#include "main.h"

/**
 * free_grid - frees a 2-dimensional array.
 *
 * @grid: Pointer to the memory block to be freed.
 * @height: Height of the array.
 *
 * Return: Void.
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
		free(grid[i]); /* Free memory allocated for each row */

	free(grid); /* Free memory allocated for rows */
}
