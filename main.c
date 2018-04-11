#include <stdio.h>
#include <string.h>
#include "location.h"
#include "object.h"
#include "misc.h"


static char input[100];

void displayEntry() {
    printf("You wake up in a circular room.\n"
    "There are doors around you numbered 1 through 6.\n"
    "There is a locked panel in the center of the room with 6 locks.\n"
    "NOTE: If you are stuck, try typing 'help'!\n");
}

static int getInput() {
    printf("> ");
    return fgets(input, sizeof(input), stdin) != NULL;
}

static int parseAndExecute() {
    char * verb = strtok(input, " \n");
    char * noun = strtok(NULL, " \n");
    if (verb != NULL) {
        // printf("%d\n", strcmp(input, "quit"));
        if (!strcmp(verb, "quit")) {
            return 0;
        } else if (!strcmp(verb, "look")){ 
            executeLook(noun);
        } else if (!strcmp(verb, "go")) {
            executeGo(noun);
        } else if (!strcmp(verb, "help")) {
            executeHelp(noun);
        } else if (!strcmp(verb, "take")){
            executeTake(noun);
        } else if (!strcmp(verb, "drop")) {
            executeDrop();
        } else {
            printf("I'm not sure what that means\n");
        }
    }
    return 1;
}

int main(void) {
    displayEntry();
    while (getInput() && parseAndExecute()); 
    printf("Goodbye... for now...\n");
    return 0;
}

