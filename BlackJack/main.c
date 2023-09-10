#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackJack.h"

Card deck[52];
int numberCards = 0;

int main()
{
    int numberOfCards = 52;
    Card deck[numberOfCards];
    initializeDeck(deck, numberOfCards);
    shuffleDeck(deck, numberOfCards); //
    return 0;
}

/*
    printf("-=-=-=-=-=-=-=-=-=");
    for (int i = 0; i < 52; i++)
    {
        printf("suit: %s rank: %s value: %d\n", deck[i].suit, deck[i].rank ,deck[i].value);
    }
 */

