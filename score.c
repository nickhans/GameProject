#include <stdio.h>

#include "score.h"
#include "player.h"

struct highscore {
    int score;
    char name[50];
};

struct highscore scores[5];

int numOfScores = sizeof(scores) / sizeof(*scores);

char * fileName = ".highscore.txt";

void formatAndDisplayTime(int time) {
    int minutes = time / 60;
    int seconds = time % 60;
    printf("%d min %d sec\n", minutes, seconds);
}

void saveHighscore() {
    FILE *scoreFile;
    

    scoreFile = fopen(fileName, "r");
    for (int i = 0; i < numOfScores; i++) {
        fscanf(scoreFile, "%s", scores[i].name);
        fscanf(scoreFile, "%d", &scores[i].score);
    }
    fclose(scoreFile);

    scoreFile = fopen(fileName, "w");
    bool scoreWritten = false;
    for (int i = 0; i < numOfScores; i++) {
        if (player.playerTime <= scores[i].score && !scoreWritten) {
            fprintf(scoreFile, "%s %d\n", player.name, player.playerTime);
            scoreWritten = true;
        } else if (scoreWritten) {
            fprintf(scoreFile, "%s %d\n", scores[i-1].name, scores[i-1].score);
        } else {
            fprintf(scoreFile, "%s %d\n", scores[i].name, scores[i].score);
        }
    }
    fclose(scoreFile);

    scoreFile = fopen(fileName, "r");
    for (int i = 0; i < numOfScores; i++) {
        fscanf(scoreFile, "%s", scores[i].name);
        fscanf(scoreFile, "%d", &scores[i].score);
    }
    fclose(scoreFile);

    for (int i = 0; i < numOfScores; i++) {
        printf("%d. %s - ", i + 1, scores[i].name);
        formatAndDisplayTime(scores[i].score);
    }
    if (scoreWritten) {
        printf("Congrats %s, you escaped with a highscore!!\n", player.name);
    } else {
        printf("Sorry %s, you weren't fast enough!! Try to win with a faster time!!\n", player.name);
    }
}
