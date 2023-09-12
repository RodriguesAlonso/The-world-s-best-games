#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackJack.h"

void introduction()
{
    char textIntro[2048];
    FILE* f = fopen("introduction.txt", "r");
    if (f == NULL){
        perror("Couldn't open introduction.txt");
    }   
    while(fgets(textIntro, sizeof(textIntro), f) !=NULL)
    {
        printf("%s", textIntro);
    }
    
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

void getChoice(Card *deck, HAND *head, int *numberCards)
{
    char choise[10];
    printf("\n** Make a choise hit: \n*>Request an additional card\n*>stand: Keep the current hand without taking any more cards.***\n");
    printf("\n** hit or stand => ");
    scanf("%s", choise);
    if (strcmp(choise, "hit") == 0)
    {
        hit(deck, head, numberCards);
        printf("\n -= Your hand is now: =-\n");
        printHand(head);
        getChoice(deck, head, numberCards);
    }
    else if (strcmp(choise, "stand") == 0)
    {
        return;
    }
    else
    {
        printf("\n**Invalid choice, please enter 'hit' or 'stand' try again,\n");
        getChoice(deck, head, numberCards);
    }
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
        printf("\n -= His hand is now: =-\n");
        dealer->point = calculatePoints(dealer);
    }

    printHand(dealer);
}

void resolution(HAND *player, HAND *dealer)
{
    printf("\n*** RESOLUTION ***\n");
    player->point = calculatePoints(player);
    dealer->point = calculatePoints(dealer);

    printf("\n=> Player Points = %d\n", player->point);
    printf("\n=> Dealer Points = %d\n", dealer->point);

    if (player->point > 21)
    {
        printf("\nPlayer lose your point is more than 21: your point is:%d\n", player->point);
    }
    else if (dealer->point > 21)
    {
        printf("\ncongratulations! Your win!\nDelear past 21 points ");
    }
    else if (dealer->point < player->point)
    {
        printf("\n ***congratulations! Your win!***\n\t your point more than the dealer's point\n");
    }
    else if (dealer->point > player->point && dealer->point <= 21)
    {
        printf("\nThe player loses his point is less than the dealer's point:");
    }
    else
    {
        printf("\n---DRAW_GAME---\n");
    }
    printf("\n");
};