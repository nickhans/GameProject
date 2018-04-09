#include <stdio.h>
#include <string.h>
#include "misc.h"

void executeHelp(const char * noun) {
    if (noun == NULL) {
        printf("List of Commands:\n"
                "go             look\n"
                "quit\n"
            "Try 'help <command>' for help on that command.\n");
    } else if (!strcmp(noun, "go")) {
        printf("Use this command to go to a new area.\n"
        "Use 'go cw' to move clockwise around rooms or 'go ccw' to move counter-clockwise.\n"
        "You can also specify a room to go to such as 'go 3' to go to room 3.\n"
        "List of avaliable rooms: 1, 2, 3, 4, 5, 6, center\n");
    } else if (!strcmp(noun, "look")) {
        printf("Use this command for looking at something specific or the contents of a room\n"
                "Try 'look around'.\n");
    } else if (!strcmp(noun, "quit")) {
        printf("Use this command to quit the game.\n"
        "WARNING: Progress will not be saved.\n");
    } else {
        printf("Please ask for help with a valid command.\n");
    }
}
