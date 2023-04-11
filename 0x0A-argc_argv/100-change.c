#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int v = 0, i = 0, coins[] = {25, 10, 5, 2, 1}, nCoins = 0, residuo = 0, div = 0;

    if (argc != 2 || (v = atoi(argv[1])) < 0)
    {
        printf("Error\n");
        return 1;
    }

    while (coins[i])
    {
        residuo = v % coins[i];
        div = v / coins[i];
        nCoins += div;
        if (residuo != 0)
            v = residuo;
        else
            break;
        i++;
    }

    printf("%d\n", nCoins);
    return 0;
}
