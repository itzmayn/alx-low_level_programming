#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - creates a password of sum 2772
 *
 * Return: 0
 */
int main(void)
{
    int keynumber = 0, checksum = 2772;
    char password[100];
    srand(time(NULL));

    while (keynumber < (checksum - 122)) {
        int symbol = (rand() % (122 - 97 + 1)) + 97;
        password[keynumber] = symbol;
        keynumber += symbol;
    }

    password[keynumber] = checksum - keynumber;
    printf("%s", password);

    return (0);
}
