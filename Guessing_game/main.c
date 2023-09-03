#include <stdio.h>
#include <stdlib.h>

void introduction()
{
    printf("\n*******************************************");
    printf("\n*Welcome to the world's best guessing game*");
    printf("\n*******************************************\n");
    printf("\nThe objective of the game is to guess a specific number correctly.\n");
}

void checkGuess(int guess, int secretNumber, int attempts)
{
    if (guess == secretNumber)
    {
        printf("\nCongratulations! You have guessed the correct number!\n");
    }
    else if (guess < secretNumber)
    {
        printf("\nYour guess is too low!\n");
    }
    else if (guess > secretNumber)
    {
        printf("\nYour guess is too high!\n");
    }
    if (attempts == 1)
    {
        printf("\nYou ran out of attempts!\n");
    }
    
}

void playGuess()
{
    int guess;
    int secretNumber = rand() % 100 + 1;
    int attempts = 5;
    introduction();

    do
    {
        printf("\nNumber of remaining attempts, attempts: %d\n", attempts);
        printf("\nTake a guess at a number: ");
        scanf("%d", &guess);
        printf("\nYour guess is %d\n", guess);

        checkGuess(guess, secretNumber, attempts);

        attempts--;

    } while (guess != secretNumber && attempts != 0);
};

int main()
{
    playGuess();
}
