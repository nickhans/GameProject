#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "location.h"
#include "misc.h"


static char input[100];

char name[50];

void displayEntry1(){
  printf("Enter Name\n");
}
static int playerName(){//stores the name of the player in name
  printf("> ");
  fgets(name, sizeof(name), stdin);
  if(*name == ' ' || name[1] == '\0' ){//make sure the name is an actual name and not just a space or a NULL
    printf("Please Enter Name\n");
    return 1;
  }
  return 0;
}
void displayEntry2() {
    int i;
    char nameOfPlayer[50];
    for(i = 0; name[i] != '\n'; i++){//erase the next line(\n) at the end of name
        nameOfPlayer[i] = name[i];
    }

    nameOfPlayer[i] = '\0';
    printf("%s, you wake up in a circular room.\n"
    "There are doors around you numbered 1 through 6.\n"
    "There is a locked panel in the center of the room with 6 locks.\n"
    "NOTE: If you are stuck, try typing 'help'!\n", nameOfPlayer);
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
        } else {
            printf("I'm not sure what that means\n");
        }
    }
    return 1;
}

int main(void) {
    displayEntry1();
    while(playerName());
    displayEntry2();
    while (getInput() && parseAndExecute());
    printf("Goodbye... for now...\n");
    return 0;
}
