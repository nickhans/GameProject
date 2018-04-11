#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "location.h"
#include "object.h"


struct location locs[] = {
    {"a circular room. There are 6 doors around you", "center", 0},
    {"Room 1", "1", 1},
    {"Room 2", "2", 2},
    {"Room 3", "3", 3},
    {"Room 4", "4", 4},
    {"Room 5", "5", 5},
    {"Room 6", "6", 6},
};

int numberOfLocations = (sizeof(locs) / sizeof(*locs));
int locationOfPlayer = 0;
bool objectInRoom = false;

void describeRoom() {
    printf("You are in %s.\n", locs[locationOfPlayer].description);
}

void executeLook(const char * noun) {
    if (noun != NULL && !strcmp(noun, "around")) {
        printf("You are in %s.\n", locs[locationOfPlayer].description);
        printf("This room contains: \n");
        for (int i = 0; i < numberOfObjects; i++) {
            if (locationOfPlayer == objs[i].locationOfObject) {
                printf("-%s\n", objs[i].objName);
                objectInRoom = true;
            }
        }
        if (!objectInRoom) printf("-nothing\n");
        objectInRoom = false;
    } else {
        printf("I don't understand what you want to see.\n");
    }
}

void executeGo (const char * noun) {
    if (noun != NULL && !strcmp(noun, "cw")) {
        if (locationOfPlayer == 6) {
            printf("Going clockwise.\n");
            locationOfPlayer = 1;
            describeRoom();
        } else if (locationOfPlayer == 0){
            printf("You cannot do that until you enter one of the numbered rooms.\n");
        } else {
            printf("Going clockwise.\n");
            locationOfPlayer++;
            describeRoom();
        }
    } else if (noun != NULL && !strcmp(noun , "ccw")) {
        if (locationOfPlayer == 1) {
            printf("Going counter-clockwise.\n");
            locationOfPlayer = 6;
            describeRoom();
        } else if (locationOfPlayer == 0){
            printf("You cannot do that until you enter one of the numbered rooms.\n");
        } else {
            printf("Going counter-clockwise.\n");
            locationOfPlayer--;
            describeRoom();
        }
    } else if (noun != NULL && !strcmp(noun, "center")) {
        if (locationOfPlayer == 0) {
            printf ("You are already there.\n");
        } else {
            printf("Going to center.\n");
            locationOfPlayer = 0;
            describeRoom();
        }
    } else if (noun != NULL && locationOfPlayer == 0) {
        for (int i = 0; i < numberOfLocations; i++) {
            if (noun != NULL && !strcmp(noun, locs[i].name)) {
                if (i == locationOfPlayer) {
                    printf("You are already there.\n");
                } else {
                    printf("Going to %s.\n", locs[i].name);
                    locationOfPlayer = i;
                    describeRoom();
                }
            }
        }
    } else {
        printf("I don't understand where you want to go.\n");
    } 
}



