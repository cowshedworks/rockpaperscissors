#include "rpslib.h"
#include <time.h>
#include <unistd.h>

int computerWins = 0;
int playerWins = 0;
int draws = 0;
int currentRound = 1;

void playRound()
{
    const char *possibleChoices[] = {"rock", "paper", "scissors"};
    int userGuess, computerGuess, randomChoice;
    computerGuess = rand() % 3;

    sleep(1);
    printf("\033[0;36mRound %d\n", currentRound);
    printf("\033[0m");

    printf("Please choose:\n1. Rock\n2. Paper\n3. Scissors\n");
    scanf("%d", &userGuess);
    if (userGuess > 3 || userGuess < 1)
    {
        printf("\033[0;31mOut of bounds!\n");
        printf("\033[0m");
        return;
    }

    userGuess = userGuess - 1;

    printf("\n");
    printf("\033[0;42mYou: %s\n", possibleChoices[userGuess]);
    printf("\033[0;44mComputer: %s\n", possibleChoices[computerGuess]);
    printf("\033[0m");
    sleep(1);
    decideWinner(userGuess, computerGuess, possibleChoices);
    printf("\n");

    sleep(2);
    printf("\033[0;36mCurrent Score\n--------------\n");
    printf("\033[0;42mYou: %d\n", playerWins);
    printf("\033[0;44mComputer: %d\n", computerWins);
    printf("\033[0;45mDraws: %d\n", draws);
    printf("\033[0;36m--------------\n\n\n");
    printf("\033[0m");

    currentRound++;
}

void decideWinner(int playerGuess, int computerGuess, const char *possibleChoices[])
{
    playerGuess = playerGuess + 1;
    computerGuess = computerGuess + 1;

    int matchedOutcomeIndex = 0;
    int outcomes[6][3] = {
        {3, 1, 1},
        {3, 2, 3},
        {2, 3, 3},
        {2, 1, 2},
        {1, 3, 1},
        {1, 2, 2}};

    if (playerGuess == computerGuess)
    {
        printf("\033[0;33mDraw\n");
        printf("\033[0m");
        draws++;
        return;
    }

    for (int x = 0; x < 6; x++)
    {
        if (outcomes[x][0] == playerGuess && outcomes[x][1] == computerGuess)
        {
            matchedOutcomeIndex = x;
            break;
        }
    }

    if (playerGuess == outcomes[matchedOutcomeIndex][2])
    {
        printf("\033[0;32mYou won\n");
        printf("\033[0m");
        playerWins++;
        return;
    }

    printf("\033[0;31mYou lost\n");
    printf("\033[0m");
    computerWins++;
    return;
}