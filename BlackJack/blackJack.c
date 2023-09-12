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

    // printf("\n=> NEW CARD %s of %s Value %d \n", newCard->card[0].rank, newCard->card[0].suit, newCard->card[0].value);

    (*numberCards)--;
    appHand(head, newCard);
}

void appHand(HAND *head, HAND *addCard)
{

    if (head == NULL)
    {
        printf("\n HEAD == NULL\n");
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

void printHand(HAND *hand)
{
    int i = 0;
    while (hand != NULL)
    {
        printf("\n * %s of %s Value = %d \n", hand->card->rank, hand->card->suit, hand->card->value);
        hand = hand->nextCard;
    }
}

void printPoint(HAND *hand)
{
    printf("\n*** \n> Player Points = %d <\n***", hand->point);
}

int calculatePoints(HAND *hand)
{
    int points = 0;
    while (hand != NULL)
    {
        points += hand->card->value;
        hand = hand->nextCard;
    }
    return points;
}

void turnDealer(Card *deck, HAND *dealer, int *numberOfCards)
{

    dealer->point = calculatePoints(dealer);
    printf("\n***Delear reveals his hand \n");
    printHand(dealer);
    printf("\n=> Dealer Points = %d\n", dealer->point);

    while (dealer->point <= 17)
    {
        printf("\n Dealer pick another card\n");
        hit(deck, dealer, numberOfCards);
        dealer->point = calculatePoints(dealer);
    }

    printHand(dealer);
}

void resolution(HAND *player, HAND *dealer)
{
    printf("\n*** RESOLUTION\n");
    player->point = calculatePoints(player);
    dealer->point = calculatePoints(dealer);

    printf("\n=> Player Points = %d\n", player->point);
    printf("\n=> Dealer Points = %d\n", dealer->point);

    if (player->point > 21)
    {
        printf("\nPlayer lose your point is more than 21: %d\n", player->point);
    }
    if (dealer->point > 21)
    {
        printf("\ncongratulations! Your win!\nDelear past 21 points ");
        
    }
    if (dealer->point < player->point)
    {
        printf("\n ***congratulations! Your win!***\n\t your point more than the dealer's point\n");
    }
    if (dealer->point > player->point && dealer->point <= 21)
    {
        printf("\nThe player loses his point is less than the dealer's point:");
    }
    if (dealer->point == player->point)
    {
        printf("\n---DRAW_GAME---\n");
    }
    printf("\n");
};