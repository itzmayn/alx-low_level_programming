#include "main.h"
/**
 * 
 * @ab: integer input
 * Return: absolute value of ab
 * _abs - a function that computes the absolute value of an integer
 */
int _abs(int ab)
{
	return (ab * ((ab > 0) - (ab < 0)));
}
