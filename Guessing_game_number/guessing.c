#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "guess.h"

void introduction()
{
    printf("\n*******************************************");
    printf("\n*Welcome to the world's best number guessing game*");
    printf("\n*******************************************\n");
    printf("\nThe goal of the game is to accurately guess a specific number within the range of 1 to 100.\n");
}

void start(GAME* game, double totalPoint, int attempt)
{
    game->totalPoints = totalPoint;
    game->attempts = attempt;
}

void createSecretNumber(GAME* game)
{
    int seconds = time(0);
    srand(seconds);
    game->secretNumber = rand() % 100 + 1;
}

int checkGuess(GAME* game)
{
    if (finish(game))
    {
        return 1;
    }

    else if (game->guess < game->secretNumber)
    {
        printf("\nYour guess is too low!\n");
        return 0;
    }
    else if (game->guess > game->secretNumber)
    {
        printf("\nYour guess is too high!\n");
        return 0;
    }    
}

void score(GAME* game)
{
    double lost = abs(game->guess - game->secretNumber) / 2.0;
    game->totalPoints -= lost;
}

int finish(GAME* game)
{
    if (game->guess == game->secretNumber)
    {
        printf("\n***********Congratulations! You have guessed the correct number!***********\n");
        return 1;
    }
    else if (game->attempts == 1)
    {
        printf("\nYou ran out of attempts!\n");
        printf("\n***********Game is over!***********\n");
        return 1;
    }
    return 0;
}

void guess(GAME* game)
{
    do
    {
        printf("\nNumber of remaining attempts, attempts: %d\n", game->attempts);
        printf("\nTake a guess at a number: ");
        scanf("%d", &game->guess);
        printf("\nYour guess is %d\n", game->guess);

        score(game);
        game->attempts--;
    } while (!checkGuess(game));
    printf("\nYour final score: ==>%2.f<==\n", game->totalPoints);
}
