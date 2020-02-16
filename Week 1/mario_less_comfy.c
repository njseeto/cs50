#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: \n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - 1 - i ; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < i + 1 ; j++)
        {
            printf("#");
        }

        // add two spaces in the middle.
        printf("  ");

        // for loop for the right side of the pyramid.
        for (int j = 0; j < i + 1 ; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}