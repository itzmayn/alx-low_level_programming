#include <stdio.h>

/**
 * init - function executed before main
 *
 * Description: This function is executed automatically before the main
 * function is called. It prints a message to the standard output.
 */
void init(void) __attribute__((constructor));
void init(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
