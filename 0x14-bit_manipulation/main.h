#include <stddef.h>
#include <stdint.h>

/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */
int _strlen(const char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int get_endianness(void);
int _putchar(char c);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);

