#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "player.h"
#include "location.h"
#include "object.h"
#include "container.h"

// creates an array of the locations in the game
struct location locs[] = {
    {"a circular room. There are 6 doors around you", "center", 0},
    {"Room 1", "1", 1},
    {"Room 2", "2", 2},
    {"Room 3", "3", 3},
    {"Room 4", "4", 4},
    {"Room 5", "5", 5},
    {"Room 6", "6", 6},
};

// variable for number of locations in array
int numberOfLocations = (sizeof(locs) / sizeof(*locs));
// creates boolean to check if player moved
bool playerMoved = false;
// creates boolean to check if there is an object in the room
bool hasObject = false;

// prints the description of the room the player is in
void describeRoom() {
    printf("You are in %s.\n", locs[player.locationOfPlayer].description);
}

// function for examining rooms or objects in that room
void executeExamine(const char * noun) {
    // checks if noun is room
    if (noun != NULL && !strcmp(noun, "room")) {
        // prints description of room
        printf("You are in %s.\n", locs[player.locationOfPlayer].description);
        //prints contents of room is there is any or '-nothing' if room is empty
        printf("This room contains: \n");
        for (int i = 0; i < numberOfObjects; i++) {
            // checks for object in room
            if (player.locationOfPlayer == objs[i].locationOfObject) {
                printf("-%s\n", objs[i].objName);
                hasObject = true;
            }
        }
        for (int i = 0; i < numberOfContainers; i++) {
            // checks for containers in room
            if (player.locationOfPlayer == contain[i].locationOfContainer) {
                printf("-%s\n", contain[i].containName);
                hasObject = true;
            }
        }
        if (!hasObject) printf("-nothing\n");
        hasObject = false; // reset hasObject to false
    // if there is a noun but it isn't room
    } else if (noun != NULL) {
        // if examined noun is an object
        if (isObject(noun)) {
            for (int i = 0; i < numberOfObjects; i++) {
                // checks if the noun is an object in the room or in the player inventory
                if (!strcmp(noun, objs[i].objName) && ((player.locationOfPlayer == objs[i].locationOfObject) 
                        || (objs[i].locationOfObject == 7))) {
                    // prints description of object
                    printf("This is %s.\n", objs[i].objDescription);
                    break;
                }
            }
        // if examined noun is a container
        } else if (isContainer(noun)) {
            for (int i = 0; i < numberOfContainers; i++) {
                // checks if the noun is a container in the room
                if (!strcmp(noun, contain[i].containName) && (player.locationOfPlayer == contain[i].locationOfContainer)) {
                    // prints the description of container
                    printf("This is %s, the %s can hold %d objects.\n", contain[i].containDesc, contain[i].containName, contain[i].containCapacity);
                    printf("The %s contains:\n", contain[i].containName);
                    for (int j = 0; j < numberOfObjects; j++) {
                        if (objs[j].locationOfObject == contain[i].containInventory) {
                            printf("-%s\n", objs[j].objName);
                            hasObject = true;
                        }
                    }
                    if (!hasObject) printf("-nothing\n");
                    hasObject = false; 
                    break;
                }
            }
        // if examined noun is neither an object or a container
        } else {
            // if the object isn't found print that the object isn't in room
            printf("I don't see that %s in this room.\n", noun);
            hasObject = false;   // reset hasObject to false
        }
    // if there is no noun print messages
    } else {
        printf("I don't understand what you want to see.\n");
    }
}

// function for navigation
void executeGo (const char * noun) {
    // if noun is cw (clockwise)
    if (noun != NULL && !strcmp(noun, "cw")) {
        // if player.locationOfPlayer is in room 6 next move to room 1
        if (player.locationOfPlayer == room6->roomNumber) {
            printf("Going clockwise.\n");
            player.locationOfPlayer = room1->roomNumber;
            describeRoom();
        // if player is in center error message
        } else if (player.locationOfPlayer == center->roomNumber){
            printf("You cannot do that until you enter one of the numbered rooms.\n");
        // move to the next clockwise room by incrementing player position
        } else {
            printf("Going clockwise.\n");
            player.locationOfPlayer++;
            describeRoom();
        }
    // if noun is ccw (counter-clockwise)
    } else if (noun != NULL && !strcmp(noun , "ccw")) {
        // if player is in room 1 move to room 6
        if (player.locationOfPlayer == room1->roomNumber) {
            printf("Going counter-clockwise.\n");
            player.locationOfPlayer = room6->roomNumber;
            describeRoom();
        // if player is in center print error message
        } else if (player.locationOfPlayer == center->roomNumber){
            printf("You cannot do that until you enter one of the numbered rooms.\n");       
        // move to the next counter-clockwise room by decrementing player position
        } else {
            printf("Going counter-clockwise.\n");
            player.locationOfPlayer--;
            describeRoom();
        }
    // if noun is center
    } else if (noun != NULL && !strcmp(noun, "center")) {
        // if player is in center print message that they are there
        if (player.locationOfPlayer == center->roomNumber) {
            printf ("You are already there.\n");       
        // else set player location to center
        } else {
            printf("Going to center.\n");
            player.locationOfPlayer = center->roomNumber;
            describeRoom();
        }
    // if player is in center and there is a noun
    } else if (noun != NULL && player.locationOfPlayer == center->roomNumber) {
        // loop through locations and check if noun == a location name
        for (int i = 0; i < numberOfLocations; i++) {
            if (noun != NULL && !strcmp(noun, locs[i].name)) {
                // if noun == room player is in let them know
                if (locs[i].roomNumber == player.locationOfPlayer) {
                    printf("You are already there.\n");
                    playerMoved = true;
                    break;
                // if noun == another room set location of player to that room
                } else {
                    printf("Going to %s.\n", locs[i].name);
                    player.locationOfPlayer = locs[i].roomNumber;
                    describeRoom();
                    playerMoved = true;
                    break;
                }
            }
        }
        // check if player didn't move then print message
        if (!playerMoved) printf("I don't understand where you want to go.\n");
        playerMoved = false; // reset playerMoved to false
    // if no noun print message
    } else {
        printf("I don't understand where you want to go.\n");
    } 
}



