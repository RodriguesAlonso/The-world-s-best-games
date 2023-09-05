#include <stdio.h>
#include <stdlib.h>

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

    while (fscanf(fp, "%[^,]%*c,%[^,]%*c,%[^,]%*c", class, word, tip) != EOF)
    {
        
        printf("%s %s %s", class, word, tip);
    }
    fclose(fp);
    return 0;
}

void bank_space()
{
}

void choice_word() {}

void play() {}

void guess() {}

int main()
{
    word();
}