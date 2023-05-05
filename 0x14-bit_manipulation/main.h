#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>

/*
 * Function:  binary_to_uint
 * --------------------
 * Convert a binary string to an unsigned integer.
 *
 *  b: the binary string.
 *
 *  returns: the converted unsigned integer.
 */
unsigned int binary_to_uint(const char *b);

/*
 * Function:  print_binary
 * --------------------
 * Print the binary representation of an unsigned integer.
 *
 *  n: the unsigned integer to be printed.
 */
void print_binary(unsigned long int n);

/*
 * Function:  get_bit
 * --------------------
 * Get the value of a bit at a given index.
 *
 *  n: the unsigned integer.
 *  index: the index of the bit to get.
 *
 *  returns: the value of the bit at the given index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index);

/*
 * Function:  set_bit
 * --------------------
 * Set the value of a bit to 1 at a given index.
 *
 *  n: a pointer to the unsigned integer.
 *  index: the index of the bit to set.
 *
 *  returns: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index);

/*
 * Function:  get_endianness
 * --------------------
 * Check the endianness of the machine.
 *
 *  returns: 0 if big endian, 1 if little endian.
 */
int get_endianness(void);

/*
 * Function:  _putchar
 * --------------------
 * Write a character to stdout.
 *
 *  c: the character to write.
 *
 *  returns: the number of characters written.
 */
int _putchar(char c);

/*
 * Function:  clear_bit
 * --------------------
 * Set the value of a bit to 0 at a given index.
 *
 *  n: a pointer to the unsigned integer.
 *  index: the index of the bit to clear.
 *
 *  returns: 1 if it worked, or -1 if an error occurred.
 */
int clear_bit(unsigned long int *n, unsigned int index);

/*
 * Function:  flip_bits
 * --------------------
 * Count the number of bits needed to be flipped to convert one number to another.
 *
 *  n: the first unsigned integer.
 *  m: the second unsigned integer.
 *
 *  returns: the number of bits needed to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

#endif /* MAIN_H_ */
