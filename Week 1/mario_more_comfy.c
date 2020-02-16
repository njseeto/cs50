#include <stdio.h>
#include <cs50.h>

int main(void) {
int height;

    do {
        // Get the pyramid height from the user.
        height = get_int("Height: \n");
    }
    // Make sure the height is between 1-8 inclusive.
    while( height < 1 || height > 8);

    // write a for loop for the spaces.
    for(int i=0; i < height; i++){
        for(int j=0; j < height-1-i ; j++){
            printf(" ");
        }

    // write a for loop for the hashes.
    for(int j=0; j< i + 1 ; j++){
        printf("#");
        }
    printf("\n");
    }

}