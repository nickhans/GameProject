#include <stdio.h>
#include <string.h>
#include "location.h"
#include "object.h"
#include "misc.h"

// creates a string variable input to hold user input (max 100 characters)
static char input[100];

// displays first message at the beginning of the game
void displayEntry() {
    printf("You wake up in a circular room.\n"
    "There are doors around you numbered 1 through 6.\n"
    "There is a locked panel in the center of the room with 6 locks.\n"
    "NOTE: If you are stuck, try typing 'help'!\n");
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
        if (!strcmp(verb, "quit")) {            // if quit returns 0 to end main loop
            return 0;
        } else if (!strcmp(verb, "examine")){   // definition in location.c
            executeExamine(noun);
        } else if (!strcmp(verb, "go")) {       // definition in location.c
            executeGo(noun);
        } else if (!strcmp(verb, "help")) {     // definition in misc.c
            executeHelp(noun);
        } else if (!strcmp(verb, "take")){      // definition in object.c
            executeTake(noun);
        } else if (!strcmp(verb, "drop")) {     // definition in object.c
            executeDrop(noun);
        } else {
            printf("I'm not sure what that means\n");
        }
    }
    return 1;   // returns 1 to continue loop
}

// main function consists mainly of game loop
int main(void) {
    // print intro message
    displayEntry();
    // loop runs getInput and parseAndExecute which will continuously loop until quit command
    while (getInput() && parseAndExecute()); 
    //print exit message
    printf("Goodbye... for now...\n");
    return 0;
}

