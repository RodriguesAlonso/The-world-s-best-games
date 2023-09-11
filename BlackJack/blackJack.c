#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackJack.h"

void introduction()
{
    printf("\n************************************************");
    printf("\n* Welcome to the world's best Black Jack game  *");
    printf("\n*************************************************\n");
    printf("\nThe objective of the game is to have a hand with a total value higher than the dealer's hand, without exceeding 21.\nHere are the basic rules of the game:");
    printf("\nCard Values:\n\tNumbered cards (2 through 10) are worth their face value.\nFace cards (Jack, Queen, King) are each worth 10 points\nAn Ace can be worth 1 or 11 points, depending on what benefits the player's hand.");
    printf("\nDealing Cards:\n\tThe dealer deals two cards to each player, including themselves. However, one of the dealer's cards is face-up (visible to players), while the other is face-down (hidden).\n");
    printf("\nPlayer Options:\n\tHit: Request an additional card from the dealer.\n\tStand: Keep the current hand without taking any more cards.\n");
    printf("\nObjective:\n\tThe goal is to get as close to 21 as possible without exceeding it. Going over 21 results in an automatic loss, regardless of the dealer's hand.\n");
    printf("\nDealer's Turn:\n\tAfter all players have made their decisions, the dealer reveals their face-down card. The dealer must hit (take another card) until their hand totals 17 or higher.");
    printf("\n************************************************");
    printf("\n");
}

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
        // printf("-=-ID-=%d-=-=-=-=-=-=Random-=%d-=-=-=-=-=-=-=-=-=-=-\n",i, nRandom);
        // printf("TEMP suit: %s rank: %s value: %d\n", temp.suit, temp.rank ,temp.value);
        // printf("CARD suit: %s rank: %s value: %d\n", deck[i].suit, deck[i].rank, deck[i].value);
        // printf("DECK RANDOM suit: %s rank: %s value: %d\n", deck[nRandom].suit, deck[nRandom].rank ,deck[nRandom].value);
    }
}
void distributeCards(Card *deck, HAND *dealer, HAND *player, int *numberCards)
{

    dealer->card[0] = deck[*numberCards - 1];
    HAND *newHand = (HAND *)malloc(sizeof(HAND));
    if (newHand == NULL)
    {
        perror("malloc failed");
        exit(1);
    }
    newHand->card[0] = dealer->card[0];
    newHand->nextCard = NULL;

    printf("\nDistribute dealer");
    printCard(dealer);
    (*numberCards)--;    

}

void printDeck(Card *deck, int numberCards)
{

    for (int i = 0; i < numberCards; i++)
    {
        printf("id %d  CARD suit: %s rank: %s value: %d\n", i, deck[i].suit, deck[i].rank, deck[i].value);
    }
}

void hit(Card *deck, HAND *head, int *numberCards)
{
    HAND *newCard = (HAND *)malloc(sizeof(HAND));
    if (newCard == NULL)
    {
        perror("malloc failure");
        exit(1);
    }
    newCard->card[0] = deck[*numberCards - 1];
    newCard->nextCard = NULL;
    printf("\n NEW CARD Rank %s Suit %s Value %d \n", newCard->card[0].rank, newCard->card[0].suit, newCard->card[0].value);

    appHand(head, newCard);
}

void appHand(HAND *head, HAND *addCard)
{

    if (head == NULL)
    {
        head = addCard;
    }
    else
    {
        HAND *current = head;
        while (current->nextCard != NULL)
        {
            current = current->nextCard;
        }
        current->nextCard = addCard;
    }
}

void printCard(HAND *hand)
{
    
    while (hand != NULL)
    {
        printf("\n Hand CARD Rank %s Suit %s Value %d \n", hand->card->rank, hand->card->suit, hand->card->value);
        hand = hand->nextCard;        
    }
    //printf("NULL\n");
}

void calculatePoints(HAND *hand){
    int points = 0;
    while (hand != NULL)
    {
        points += hand->card->value;
        hand = hand->nextCard;        
    }
    printf("\n Total Points: %d\n", points);
}

