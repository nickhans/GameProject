#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <sys/time.h> // used to find elapsed time


// user made libraries
#include "location.h"
#include "object.h"
#include "misc.h"
#include "player.h"
#include "container.h"
#include "score.h"

// variables from sys/time.h used for finding elapsed time
struct timeval t1, t2;
// creates a string variable input to hold user input (max 100 characters)
static char input[100];
// creates a string variable to temporarily hold player name
char name[50];

bool hasCircle = false;
bool hasSquare = false;
bool hasTriangle = false;
bool hasStar = false;

// function to get players name and store it in player struct
static int playerName() { // stores the name of the player in name
    printf("Enter Name\n");
    printf("> ");
    fgets(name, sizeof(name), stdin);
    if (*name == ' ' || name[1] == '\0' ) { // make sure the name is an actual name and not just a space or a NULL
        printf("Please Enter Name\n");
        return 1;
    }
    return 0;
}

// displays first message at the beginning of the game
void displayEntry() {
    int i;
    for (i = 0; name[i] != '\n'; i++) { //erase the next line(\n) at end of name
        player.name[i] = name[i];
    }

    player.name[i] = '\0';

    printf("%s, you wake up in a circular room.\n"
    "There are doors around you numbered 1 through 6.\n"
    "There is a locked panel in the center of the room \nwith 4 different shapes, "
    "a square, a circle, a triangle, and a star.\n"
    "NOTE: If you are stuck, try typing 'help'!\n", player.name);
}

bool didWin() {
    for (int i = 0; i < numberOfObjects; i++) {
        if (!strcmp(objs[i].objName, "circle") && objs[i].locationOfObject == trapdoor->containInventory) {
            hasCircle = true;
        }
        if (!strcmp(objs[i].objName, "square") && objs[i].locationOfObject == trapdoor->containInventory) {
            hasSquare = true;
        }
        if (!strcmp(objs[i].objName, "triangle") && objs[i].locationOfObject == trapdoor->containInventory) {
            hasTriangle = true;
        }
        if (!strcmp(objs[i].objName, "star") && objs[i].locationOfObject == trapdoor->containInventory) {
            hasStar = true;
        }
    }
    if (hasCircle && hasSquare && hasTriangle && hasStar) {
        return true;
    } else {
        hasCircle = false;
        hasSquare = false;
        hasTriangle = false;
        hasStar = false;
        return false;
    }
}

void formatAndDisplayTime(int time) {
    int minutes = time / 60;
    int seconds = time % 60;
    printf("Your time: %d min %d sec\n", minutes, seconds);
}

void displayQuit() {
    //print exit message
    printf("Goodbye... for now...\n");
}

void displayEnd() {
    printf("Congrats you escaped!\n");
}

// gets the input of the user from the standard in
static int getInput() {
    printf("> ");
    return fgets(input, sizeof(input), stdin) != NULL;
}

// parses input and decides what to execute
static int parseAndExecute() {
    // split input into two parts a verb and a noun, verb dictates what command is executed
    char * verb = strtok(input, " \n");
    char * noun = strtok(NULL, " \n");   
    // checks for valid verb input   
    if (verb != NULL) {
        // checks for various commands, if command is not found prints message at end
        if (!strcmp(verb, "quit")) { 
            displayQuit();           // if quit returns 0 to end main loop
            return 0;
        } else if (!strcmp(verb, "examine")){       // definition in location.c
            executeExamine(noun);
        } else if (!strcmp(verb, "go")) {           // definition in location.c
            executeGo(noun);
        } else if (!strcmp(verb, "help")) {         // definition in misc.c
            executeHelp(noun);
        } else if (!strcmp(verb, "take")){          // definition in object.c
            executeTake(noun);
        } else if (!strcmp(verb, "drop")) {         // definition in object.c
            executeDrop(noun);
        } else if (!strcmp(verb, "inventory")) {    // definition in player.c
            executeInventory();
        } else if (!strcmp(verb, "put")) {
            executePut(noun);
            if (!strcmp(noun, "trapdoor")) {
                if (didWin()) {
                    displayEnd();
                    return 0;
                }
            }
        } else if (!strcmp(verb, "remove")) {
            executeRemove(noun);
        } else {
            printf("I'm not sure what that means\n");
        }
    }
    return 1;   // returns 1 to continue loop
}

// main function consists mainly of game loop
int main(void) {

    // gets player name
    while(playerName());
    // prints intro to game
    displayEntry();
    // get time at start of program
    gettimeofday(&t1, NULL);
    // loop runs getInput and parseAndExecute which will continuously loop until quit command
    while (getInput() && parseAndExecute()); 
    // get time at end of program
    gettimeofday(&t2, NULL);
    // find the difference between start time and end time
    int elapsedTime = (t2.tv_sec - t1.tv_sec);
    player.playerTime = elapsedTime;
    // print the elapsed time
    formatAndDisplayTime(elapsedTime);
    if (didWin()) {
        printf("Checking for highscore...\n");
        saveHighscore();
    }
    return 0;
}

