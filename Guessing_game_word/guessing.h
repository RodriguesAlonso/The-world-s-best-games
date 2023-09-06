void introduction();
char *getLineRandom();
int secreatWord(char *category, char *word, char *tip);
void chosenLetter(char letters[26], int *attempts);
int hits(char word, char letters[26], int attempts);
char *makeGuess();
void makeBoard(char word[26], char letters[26], int attempts);
int checkGuess(char *guess, char *word,int attempts, char *tip);