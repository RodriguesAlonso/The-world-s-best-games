#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackJack.h"

void initializeDeck(Card *deck, int numberCards)
{
    char suits[][20] = {"Hearts", "Diamonds", "Clubs", "Espades"};
    char ranks[][10] = {"two",
                        "three",
                        "four",
                        "five",
                        "six",
                        "seven",
                        "eight",
                        "nine",
                        "ten",
                        "jack",
                        "Queen",
                        "King",
                        "Ace"};
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    int cardIndex = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            strcpy(deck[cardIndex].suit, suits[i]);
            strcpy(deck[cardIndex].rank, ranks[j]);
            deck[cardIndex].value = values[j];
            cardIndex++;
        }
    }
}

void shuffleDeck(Card deck[], int numberCards)
{
    srand(time(NULL));
    for (int i = numberCards - 1; i > 0; i--)
    {
        int nRandom = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[nRandom];
        deck[nRandom] = temp;
    }
}
void distributeCards(Card *deck, HAND *dealer, HAND *player, int *numberCards)
{
    dealer->card[0] = deck[*numberCards - 1];
    player->card[0] = deck[*numberCards - 2];

    (*numberCards)--;
    (*numberCards)--;

    hit(deck, player, numberCards);
    hit(deck, dealer, numberCards);

    printf("\n*** DELEAR reveals his card: %s of %s  value: %d ***\n", dealer->card[0].rank, dealer->card[0].suit, dealer->card[0].value);

    printf("\n -= Your hand is now: =-\n");
    printHand(player);
}

void printDeck(Card *deck, int numberCards)
{

    for (int i = 0; i < numberCards; i++)
    {
        printf("id %d  CARD suit: %s rank: %s value: %d\n", i, deck[i].suit, deck[i].rank, deck[i].value);
    }
}
