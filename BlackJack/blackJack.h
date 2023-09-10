typedef struct{
    char suit[20];
    char rank[20];
    int value;
} Card;



void introduction();
void initializeDeck(Card* deck, int numberCards);
void shuffleDeck(Card deck[], int numberCards);
void play();
void game();
void dealCards();
int calculatePoints();
void hit();
void resolution();
int getChoice();
