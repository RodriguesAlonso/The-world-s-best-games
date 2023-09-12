#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackJack.h"

int main()
{
    introduction();
    int numberOfCards = 52;
    Card deck[numberOfCards];
    HAND player[50];
    HAND dealer[50];

    initializeDeck(deck, numberOfCards);

    shuffleDeck(deck, numberOfCards);

    distributeCards(deck, dealer, player, &numberOfCards);
    
    getChoice(deck, player, &numberOfCards);
    turnDealer(deck, dealer, &numberOfCards);
    resolution(player, dealer);
}