#include "main.h"
#include <stdio.h>

/**
 * _atoi - convert a string to an integer.
 * @s: input string
 * Return: integer value
 */
int _atoi(char *s)
{
    int num = 0, sign = 1;
    while (*s != '\0') {
        if (*s == '-') {
            sign = -sign;
        }
        else if (*s >= '0' && *s <= '9') {
            num = num * 10 + (*s - '0');
            if (*(s + 1) < '0' || *(s + 1) > '9') {
                break;
            }
        }
        s++;
    }
    return num * sign;
}
