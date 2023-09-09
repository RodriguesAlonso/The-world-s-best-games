struct game
{
    int guess;
    int secretNumber;
    double totalPoints;
    int attempts;
};

typedef struct game GAME;

void introduction();
void createSecretNumber(GAME* game);
void score(GAME* game);
void guess(GAME* game);
void start(GAME* game, double totalPoint, int attempt);
int checkGuess(GAME* game);
int finish(GAME* game);