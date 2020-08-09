#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;

    // Take input till get the valid input
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // Convert dollars to cents
    int cents = round(dollars * 100);

    int total = 0, count = 0;

    // Coins available
    int coins[4] = {25, 10, 5, 1};

    // Loop through coins and find the no of coins used and add to total coins used
    for (int i = 0; i < 4; ++i)
    {
        count = (int)cents / (int)coins[i];
        cents -= coins[i] * count;
        total += count;
    }

    printf("%d\n", total);

    return 0;

}
