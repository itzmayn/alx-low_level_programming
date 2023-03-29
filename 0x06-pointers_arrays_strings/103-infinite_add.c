#include "main.h"
/**
 * print_buffer - add 2 strings.
 * @b: string1.
 * @size: string2.
 * Return: String with all letters in ROT13 base.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = strlen(n1);
    int len2 = strlen(n2);
    int len = len1 > len2 ? len1 : len2;
    int carry = 0;

    if (len + 1 > size_r) {
        return NULL;
    }

    r[len + 1] = '\0';

    while (len--) {
        int d1 = len1 > 0 ? n1[--len1] - '0' : 0;
        int d2 = len2 > 0 ? n2[--len2] - '0' : 0;
        int sum = d1 + d2 + carry;

        if (sum > 9) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }

        r[len + 1] = sum + '0';
    }

    if (carry) {
        r[0] = '1';
        return r;
    }

    return r + 1;
}
