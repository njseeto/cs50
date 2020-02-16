#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
float dollars;
do
    {
    dollars = get_float("Change owed:\n");
    }
while (dollars < 0); // ensures the input is a positive number

int cents = round(dollars * 100);
int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;
int coinsUsed = 0; // variable to hold the number of coins used for change
int denominations[] = {25, 10, 5, 1};

for (int i = 0; i < 4; i++)
    {
    while (cents >= denominations[i]) // cycles through each of the denominations
        {
            coinsUsed ++;
            cents -= denominations[i]; // updates change owed as required
        }
    }

    printf("%i\n", coinsUsed);

}
