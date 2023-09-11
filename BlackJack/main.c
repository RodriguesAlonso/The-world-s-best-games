#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackJack.h"

int main()
{
    int numberOfCards = 52;
    int *sizeDesck = &numberOfCards;

    Card deck[numberOfCards];

    initializeDeck(deck, numberOfCards);
    shuffleDeck(deck, numberOfCards);

    HAND player[50];
    HAND dealer[50];
    
    
    distributeCards(deck, dealer, player, &numberOfCards);
    printf("\n-=NumberOfCard %d-\n", numberOfCards);    
    hit(deck, dealer, &numberOfCards);
    
    printCard(dealer);
    calculatePoints(dealer);  
    
    hit(deck, dealer, &numberOfCards);
    calculatePoints(dealer);          
    
    printCard(dealer);

}

/*
    printf("-=-=-=-=-=-=-=-=-=");
    for (int i = 0; i < 52; i++)
    {
        printf("suit: %s rank: %s value: %d\n", deck[i].suit, deck[i].rank ,deck[i].value);
    }
 */
