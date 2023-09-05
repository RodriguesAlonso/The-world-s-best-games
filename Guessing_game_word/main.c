#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introduction()
{
}

char word()
{
    const char *words = "words.csv";
    FILE *fp = fopen(words, "r");

    if (fp == NULL)
    {
        perror("Cannot open words list file");
        return 1;
    };

    char line[2048];
    char class[60];
    char word[60];
    char tip[60];
    int i = 0;

    while (fscanf(fp, "%[^,]%*c,%[^,]%*c,%[^,]%*c", class, word, tip) != EOF)
    {
        printf("%s %s %s", class, word, tip);
    }
    fclose(fp);
    return 0;
};

void bank_space()
{
}

void choice_word() {}

void play() {}

void guess() {}

int main()
{
    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do {

        for(int i = 0; i < strlen(palavrasecreta); i++) {
            int achou = 0;

            for(int j = 0; j < tentativas; j++) {
                if(chutes[j] == palavrasecreta[i]) {
                    achou = 1;
                    break;
                }
            }

            if(achou) {
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        char chute;
        printf("Qual letra? ");
        scanf(" %c", &chute);

        chutes[tentativas] = chute;
        tentativas++;


    } while (!acertou && !enforcou);
    
}
