typedef struct{
    char suit[10];
    char rank[10];
    int value;
} Card;

struct Hand {
    Card card[10];
    int point;
    struct Hand* nextCard;
};

typedef struct Hand HAND;

void introduction();
void initializeDeck(Card* deck, int numberCards);
void shuffleDeck(Card deck[], int numberCards);
void distributeCards(Card *deck, HAND *dealer, HAND *player, int *numberCards);
void hit(Card *deck, HAND *head, int *numberCards);
void appHand(HAND* head, HAND *newCard);
int calculatePoints(HAND *head);
void turnDealer(Card *deck, HAND *dealer, int *numberOfCards);
void resolution(HAND *player, HAND *dealer);

int getChoice();
void printDeck(Card *deck, int numberCards);
void printHand(HAND* hand);
void printPoint(HAND *hand);
;
