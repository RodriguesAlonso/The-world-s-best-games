#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estruturas para representar as cartas
struct Card
{
    char suit[10];
    char face[10];
    int value;
};

// Funções
void introduction();
void play();
void game();
void shuffleDeck();
void dealCards();
int calculatePoints();
void hit();
void resolution();
int getChoice();

int main()
{

}
