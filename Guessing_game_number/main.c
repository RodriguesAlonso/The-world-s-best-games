#include <time.h>
#include "guess.h"

GAME game;

int main()
{
    introduction();
    start(&game, 1000.0, 7);
    guess(&game);
}
