#include <stdio.h>
#include <string.h>
#include "location.h"


struct location locs[] = {
    {"a circular room. There are 6 doors around you", "center"},
    {"Room 1", "1"},
    {"Room 2", "2"},
    {"Room 3", "3"},
    {"Room 4", "4"},
    {"Room 5", "5"},
    {"Room 6", "6"},
};

static int numberOfLocations = (sizeof(locs) / sizeof(*locs));
static int locationOfPlayer = 0;

void executeLook(const char * noun) {
    if (noun != NULL && !strcmp(noun, "around")) {
        printf("You are in %s.\n", locs[locationOfPlayer].description);
    } else {
        printf("I don't understand what you want to see.\n");
    }
}

void executeGo (const char * noun) {
    if (noun != NULL && !strcmp(noun, "cw")) {
        if (locationOfPlayer == 6) {
            printf("Going clockwise.\n");
            locationOfPlayer = 1;
            executeLook("around");
        } else if (locationOfPlayer == 0){
            printf("You cannot do that until you enter one of the numbered rooms.\n");
        } else {
            printf("Going clockwise.\n");
            locationOfPlayer++;
            executeLook("around");
        }
    } else if (noun != NULL && !strcmp(noun , "ccw")) {
        if (locationOfPlayer == 1) {
            printf("Going counter-clockwise.\n");
            locationOfPlayer = 6;
            executeLook("around");
        } else if (locationOfPlayer == 0){
            printf("You cannot do that until you enter one of the numbered rooms.\n");
        } else {
            printf("Going counter-clockwise.\n");
            locationOfPlayer--;
            executeLook("around");
        }
    } else if (noun != NULL && !strcmp(noun, "center")) {
        if (locationOfPlayer == 0) {
            printf ("You are already there.\n");
        } else {
            printf("Going to center.\n");
            locationOfPlayer = 0;
            executeLook("around");
        }
    } else if (noun != NULL && locationOfPlayer == 0) {
        for (int i = 0; i < numberOfLocations; i++) {
            if (noun != NULL && !strcmp(noun, locs[i].name)) {
                if (i == locationOfPlayer) {
                    printf("You are already there.\n");
                } else {
                    printf("Going to %s.\n", locs[i].name);
                    locationOfPlayer = i;
                    executeLook("around");
                }
            }
        }
    } else {
        printf("I don't understand where you want to go.\n");
    } 
}



