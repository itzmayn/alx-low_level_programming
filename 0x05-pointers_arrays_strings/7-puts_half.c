#include "main.h"
/**
 * puts_half - prints the last half of a string.
 * @str: input string
 */
void puts_half(char *str)
{
    int length = 0;
    while (*(str + length) != '\0') {
        length++;
    }

    int start = (length + 1) / 2;
    while (*(str + start) != '\0') {
        _putchar(*(str + start));
        start++;
    }
    _putchar('\n');
}
