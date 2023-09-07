#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "guessing.h"

void introduction()
{
    printf("\n************************************************");
    printf("\n* Welcome to the world's best word guessing game *");
    printf("\n*************************************************\n");
    printf("\nWord Guessing Game: The computer selects a random word, and the player must guess what that word is by providing letter guesses.");
    printf("\nThe player has six attempts before losing the game.\n");
}

char *getLineRandom()
{
    const char *words = "words.csv";
    FILE *fileOpen = fopen(words, "r");
    if (fileOpen == NULL)
    {
        perror("Error: Could not open file");
        return NULL;
    }

    char line[1024];
    char randomLine[1024];
    int contLine = 0;

    srand(time(NULL));
    while (fgets(line, sizeof(line), fileOpen) != NULL)
    {
        contLine++;

        if (rand() % contLine == 0)
        {
            strcpy(randomLine, line);
        }
    }

    fclose(fileOpen);
    return strdup(randomLine);
}

int secreatWord(char *category, char *word, char *tip)
{
    char *randomLine = getLineRandom();

    if (randomLine != NULL)
    {
        sscanf(randomLine, "%[^,], %[^,], %[^,]", category, word, tip);
        // printf("Category: %s, Word: %s, Tip: %s\n", category, word, tip); debug print
        printf("The secret word category is =>%s<=\n", category);
        free(randomLine);
    }

    return 0;
}

void chosenLetter(char letters[26], int *attempts)
{
    printf("Your %dº attempt\n", *attempts + 1);
    char letter;
    printf("choose a letter: ");
    scanf(" %c", &letter);

    letters[(*attempts)] = letter;
    (*attempts)++;
}

int hits(char word, char letters[26], int attempts)
{
    int hit = 0;
    for (int j = 0; j < attempts; j++)
    {
        if (letters[j] == word)
        {
            hit = 1;
            break;
        }
    }
    return hit;
}

char *makeGuess()
{
    char *guess = malloc(26);
    if (guess == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }

    printf("\nMake a guess: ");
    scanf(" %25s", guess);
    printf("\nyour guess is %s\n", guess);

    return guess;
}

void makeBoard(char word[26], char letters[26], int attempts)
{
    for (int i = 0; i < strlen(word); i++)
    {
        int hit = hits(word[i], letters, attempts);
        if (hit)
        {
            printf("%c", word[i]);
        }
        else
        {
            printf("_ ");
        }
    }
}

int checkGuess(char *guess, char *word, int attempts, char *tip)
{
    int endGame = 0;

    if (strcmp(guess, word) == 0)
    {
        endGame = 1;
        printf("\n***********Congratulations! You have guessed the correct word!***********\n");
    }

    else if (attempts > 5)
    {
        printf("\nYou have no more tries!\n=>GameOver</\n");
        endGame = 1;
        printf("the secreat word is ****%s****\n", word);
    }
    else if (attempts == 3)
    {
        printf("Tip:\n==>%s", tip);
    }
    
    return endGame;
}

int main()
{
    char secretWord[20];
    char letters[26];
    int attempts = 0;
    char category[26];
    char word[26];
    char tip[60];
    int endGame = 0;
    char *guess;
    introduction();
    secreatWord(category, word, tip);

    do
    {
        makeBoard(word, letters, attempts);
        printf("\n");
        chosenLetter(letters, &attempts);
        makeBoard(word, letters, attempts);
        printf("\n");
        guess = makeGuess();
        endGame = checkGuess(guess, word, attempts, tip);
    } while (!endGame);

    return 0;
}
