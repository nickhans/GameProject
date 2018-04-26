#include <stdio.h>

#include "score.h"
#include "player.h"

void saveHighscore() {
    FILE *scoreFile;

    scoreFile = fopen("highscore.txt", "w+");
    fprintf(scoreFile, "this is a high score");
    fclose(scoreFile);

}
