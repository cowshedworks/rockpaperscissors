#include <stdio.h>
#include <stdlib.h>
#include "rpslib.c"

int main()
{
    srand(time(NULL));
    printf("Welcome to Rock Paper Scissors\n\n");
    while (1)
    {
        playRound();
    }
    return 0;
}
