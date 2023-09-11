typedef struct{
    char suit[10];
    char rank[10];
    int value;
} Card;

struct Hand {
    Card card[10];
    struct Hand* nextCard;
};

typedef struct Hand HAND;

void introduction();
void initializeDeck(Card* deck, int numberCards);
void shuffleDeck(Card deck[], int numberCards);
void distributeCards(Card *deck, HAND *dealer, HAND *player, int *numberCards);
void hit(Card *deck, HAND *head, int *numberCards);
void appHand(HAND* head, HAND *newCard);
void play();
void game();
void dealCards();
int calculatePoints();
void resolution();
int getChoice();
void printDeck(Card *deck, int numberCards);
void printCard(HAND* hand)
;
