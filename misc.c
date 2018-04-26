#include <stdio.h>
#include <string.h>
#include "misc.h"

// function to print help messages
void executeHelp(const char * noun) {
    // if there is no noun print list of commands
    if (noun == NULL) {
        printf("The goal of this game is to find 6 keys and to put them\n in the trapdoor in the center room.\n"
            "Some objects can hold other objects, we will call these containers.\n"
            "List of Commands:\n"
                "go             examine\n"
                "take           drop\n"
                "put            remove\n"
                "inventory      quit\n"
            "Try 'help <command>' for help on that command.\n");
    // if noun is go print go help message
    } else if (!strcmp(noun, "go")) {
        printf("Use this command to go to a new area.\n"
                "Use 'go cw' to move clockwise around rooms or 'go ccw' to move counter-clockwise.\n"
                "You can also specify a room to go to such as 'go 3' to go to room 3.\n"
                "List of avaliable rooms: 1, 2, 3, 4, 5, 6, center\n");
    // if noun is examine print examine help message
    } else if (!strcmp(noun, "examine")) {
        printf("Use this command for looking at something specific or the contents of a room\n"
                "Try 'examine room'.\n");
    // if noun is take print take help message
    } else if (!strcmp(noun, "take")){
        printf("Use this command to pick up objects from a room: 'take <object>'\n"
                "Remember you can only pick up one object at a time!\n"
                "Try finding the objects in a room using 'examine room'\n");
    // if noun is drop print drop help message
    } else if (!strcmp(noun, "drop")){
        printf("Use this command to drop the item you are carrying\n"
                "For this command you don't need to type the object name, just 'drop'\n");
    // if noun is quit print quit help message
    } else if (!strcmp(noun, "quit")) {
        printf("Use this command to quit the game.\n"
                "WARNING: Progress will not be saved.\n");
    // if noun is inventory print inventory help message
    } else if (!strcmp(noun, "inventory")) {
        printf("Use this command to check the inventory of the player.\n"
                "This command only needs 'inventory'.\n");
    // if noun is none of the above
    } else if (!strcmp(noun, "put")) {
        printf("Use this command to put the object in your inventory into a container.\n"
                "This command needs only the container you want to put your object in.\n"
                "Example: 'put <container>'\n"
                "Note: You must be holding an object to use this command.\n");
    } else if (!strcmp(noun, "remove")) {
        printf("Use this command to remove an object from a container and put it into your inventory.\n"
                "Specify the item you want to remove and it will next prompt \nwhich container you want to remove from.\n"
                "Example: 'remove <object>' then it will prompt for which container.\n");
    } else {
        printf("Please ask for help with a valid command.\n");
    }
}
