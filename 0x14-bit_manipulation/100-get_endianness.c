#include "main.h"

/**
 * get_endianness - Check the endianness of the machine
 *
 * Return: 0 if big-endian, 1 if little-endian
 */
int get_endianness(void)
{
    uint16_t i = 1;
    uint8_t *p = (uint8_t *)&i;

    /* If the value at the lowest address is 1, the machine is little-endian */
    if (*p == 1)
        return 1;
    else
        return 0;
}
