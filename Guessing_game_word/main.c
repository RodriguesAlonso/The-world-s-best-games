#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
        return NULL; // Retornar um ponteiro nulo em caso de erro
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
    char *randomLine = getLineRandom(); // Correção: atribuir o valor retornado por getLineRandom a randomLine

    if (randomLine != NULL)
    {
        sscanf(randomLine, "%[^,], %[^,], %[^,]", category, word, tip);
        printf("Category: %s, Word: %s, Tip: %s\n", category, word, tip);

        // Imprime a linha aleatória escolhida
        printf("Linha aleatória do fileOpen:\n%s", randomLine);
        free(randomLine); // Liberar a memória alocada para randomLine
    }

    return 0;
}

void chosenLetter(char letters[26], int *attempts)
{
    char letter;
    printf("choose a letter: ");
    scanf(" %c", &letter);

    letters[(*attempts)] = letter;
    (*attempts)++;
}

int main()
{
    int attempts = 6;
    int winner = 0;
    char letters[26];
    char letter[26];

    char category[26];
    char word[26];
    char tip[60];
    secreatWord(category, word, tip);
    introduction();
    char secretWord[20];
    printf("\n %s\n", secretWord);
    printf("\n %s\n", word);
    for (int i = 0; i < strlen(word); i++)
    {
        printf("Letter: %c\n", word[i]);
    }

    do
    {
        printf("You have %d  chutes\n", attempts);

        for (int i = 0; i < strlen(word); i++)
        {
            int hit = 0;
            for (int j = 0; j < attempts; j++)
            {
                if (letters[j] == word[i])
                {
                    hit = 1;
                    break;
                }
            }
            if (hit)
            {
                printf("%c", word[i]);
            }
            else
            {
                printf("_ ");
            }
        }
    printf("\n");
    chosenLetter(letters, &attempts);
    }
    while (!winner);
return 0;
}


