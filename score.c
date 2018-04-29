#include <stdio.h>

// user made libraries
#include "score.h"
#include "player.h"

// struct to hold current highscores from .highscore.txt
struct highscore {
    int score;
    char name[50];
};

// creates an array of 5 highscores
struct highscore scores[5];
// int to hold the number of highscores in highscore array
int numOfScores = sizeof(scores) / sizeof(*scores);
// string to hold the name of the file the highscores are held in
char * fileName = ".highscore.txt";
// a pointer to a file is needed when opening files
FILE *scoreFile;

// a function to take the times in seconds and format them to 
// minute second form and print them
void formatAndDisplayTime(int time) {
    int minutes = time / 60;
    int seconds = time % 60;
    printf("%d min %d sec\n", minutes, seconds);
}

// function to print highscores this function reads the current 
// highscores and stores them in the scores array then prints them
void printHighscore() {
    // open .highscore.txt
    scoreFile = fopen(fileName, "r");
    // increment through scores array and take name of player and their score
    for (int i = 0; i < numOfScores; i++) {
        fscanf(scoreFile, "%s", scores[i].name);
        fscanf(scoreFile, "%d", &scores[i].score);
    }
    // must close file after
    fclose(scoreFile);

    // increment through scores array and print the names of the player 
    // and their time formatted from seconds to minute second
    printf("Highscores\n");
    for (int i = 0; i < numOfScores; i++) {
        printf("%d. %s - ", i + 1, scores[i].name);
        formatAndDisplayTime(scores[i].score);
    }
}

// this function checks if the players score after being the game
// is better than current highscores then prints highscores
void saveHighscore() {
    // open file .highscore.txt in read mode
    scoreFile = fopen(fileName, "r");
    // get current highscores and store in scores array
    for (int i = 0; i < numOfScores; i++) {
        fscanf(scoreFile, "%s", scores[i].name);
        fscanf(scoreFile, "%d", &scores[i].score);
    }
    // close .highscore.txt
    fclose(scoreFile);

    // open file .highscore.txt in write mode
    scoreFile = fopen(fileName, "w");
    // boolean to store if the players score is a highscore
    bool scoreWritten = false;
    for (int i = 0; i < numOfScores; i++) {
        // if players score is less than a current highscore and the players score hasn't
        // been added to the highscore file yet
        if (player.playerTime <= scores[i].score && !scoreWritten) {
            // print the players name and score to the highscore file and change scoreWritten to true
            fprintf(scoreFile, "%s %d\n", player.name, player.playerTime);
            scoreWritten = true;
        // if the players highscore has been written print rest of highscores but shift them all down 1
        } else if (scoreWritten) {
            fprintf(scoreFile, "%s %d\n", scores[i-1].name, scores[i-1].score);
        // else just print the current highscores in their normal order
        } else {
            fprintf(scoreFile, "%s %d\n", scores[i].name, scores[i].score);
        }
    }
    // close .highscore.txt
    fclose(scoreFile);

    // print the highscores
    printHighscore();
    // if the players score madde the highscores list congradulate them else tell them to get a better time
    if (scoreWritten) {
        printf("Congrats %s, you escaped with a highscore!!\n", player.name);
    } else {
        printf("Sorry %s, you weren't fast enough!! Try to win with a faster time!!\n", player.name);
    }
}


