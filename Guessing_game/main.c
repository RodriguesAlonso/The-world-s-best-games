#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void introduction()
{
    printf("\n*******************************************");
    printf("\n*Welcome to the world's best guessing game*");
    printf("\n*******************************************\n");
    printf("\nThe goal of the game is to accurately guess a specific number within the range of 1 to 100.\n");
}

double createSecretNumber(){
    int seconds = time(0);
    srand(seconds);
    return rand() % 100 + 1;    
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
    else if (attempts == 1)
    {
        printf("\nYou ran out of attempts!\n");
    }
}

double lostPoints(int guess, int secretNumber)
{
    double lost = abs(guess - secretNumber) / 2.0;
    return lost;
}

double scorePoints(double totalPoints, double lostPoints)
{
    return totalPoints - lostPoints;
}

void guess()
{
    int guess;
    int secretNumber = createSecretNumber();
    double totalPoints = 1000.0;

    printf("\nSecret number: %d\n", secretNumber); // debug print
    int attempts = 7;
    do
    {
        printf("\nNumber of remaining attempts, attempts: %d\n", attempts);
        printf("\nTake a guess at a number: ");
        scanf("%d", &guess);
        printf("\nYour guess is %d\n", guess);

        totalPoints = scorePoints(totalPoints, lostPoints(guess, secretNumber));

        checkGuess(guess, secretNumber, attempts);
        attempts--;        
        printf("\nYour final score is %2.f\n", totalPoints);
    } while (guess != secretNumber && attempts != 0);
}

void playGuess()
{
    introduction();
    guess();
};

int main()
{
    playGuess();
}
