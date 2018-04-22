#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "object.h"
#include "location.h"
#include "player.h"

// creates array of objects
struct object objs[] = {
    {"a small ebony circle", "circle", 1},
    {"a small silver square", "square", 2},
    {"a small bronze triangle", "triangle", 3},
    {"a small golden star", "star", 4},
    {"an old leather book", "book", 2},
    {"a wooden chair", "chair", 4},
    {"a ceramic tile", "tile", 5}
};

// creates int for number of objects in array of objects
int numberOfObjects = (sizeof(objs) / sizeof(*objs));
// bool to note it an object was taken
bool objectTaken = false;

// function to check if given noun is an object
bool isObject(const char * noun) {
    for (int i = 0; i < numberOfObjects; i++) {
        if (!strcmp(noun, objs[i].objName)) return true;
    }
    return false;
}
// function to take object and put it in player inventory
void executeTake(const char * noun) {
    // if player is carrying an object print message
    if (checkPlayer() == true) {
        printf("You are already carrying something!\n");
    // if there is a noun and player isn't carrying an object
    } else if (noun != NULL && !checkPlayer()) {
        for (int i = 0; i < numberOfObjects; i++) {
            // for each object compare the name to the noun input
            // if they match change object location to player inventory
            if (!strcmp(noun, objs[i].objName)) {
                objs[i].locationOfObject = player.playerInventory;
                printf("%s taken\n", objs[i].objName);
                objectTaken = true;
                break;
            }
        }
        // if no objects were taken print that the object isn't here
        if (!objectTaken) printf("That object is not here.\n");
    // if there is no noun print message
    } else {
        printf("I'm not sure what you want to take.\n");
    }
}

// function for dropping the object in player inventory
// object should drop if the correct noun is given or if just drop is typed
void executeDrop(const char * noun) {
    // checks if player is holding an object
    if (checkPlayer() == true) {
        for (int i = 0; i < numberOfObjects; i++) {
            // checks each object for object location == player inventory
            if ( objs[i].locationOfObject == player.playerInventory) {
                // if no noun set object location to location of player
                if (!noun) {
                    objs[i].locationOfObject = player.locationOfPlayer;
                    printf("%s dropped.\n", objs[i].objName);
                    break; 
                // if noun matches object name of object set object location to location of player
                } else if (!strcmp(noun, objs[i].objName)) {
                    objs[i].locationOfObject = player.locationOfPlayer;
                    printf("%s dropped.\n", objs[i].objName);
                    break;
                // if neither, print that player isn't holding that object
                } else {
                    printf("You aren't carrying that!\n");
                }
            }
        }
        // if player has nothing print message
    } else {
        printf("You have nothing to drop!\n");
    }
}
