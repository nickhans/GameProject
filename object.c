#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "object.h"
#include "location.h"

struct object objs[] = {
    {"a small golden key", "key", 2},
    {"a new object", "object", 2}
};

int numberOfObjects = (sizeof(objs) / sizeof(*objs));
bool objectTaken = false;

int playerInventory = 7;

bool checkPlayer() {
    for (int i = 0; i < numberOfObjects; i++) {
        if (objs[i].locationOfObject == playerInventory) return true;
    }
    return false;
}

void executeTake(const char * noun) {
    if (checkPlayer() == true) {
        printf("You are already carrying something!\n");
    } else if (noun != NULL && !checkPlayer()) {
        for (int i = 0; i < numberOfObjects; i++) {
            if (!strcmp(noun, objs[i].objName)) {
                objs[i].locationOfObject = playerInventory;
                printf("%s taken\n", objs[i].objName);
                objectTaken = true;
                break;
            }
        }
        if (!objectTaken) printf("That object is not here.\n");
    } else {
        printf("I'm not sure what you want to take.\n");
    }
}

void executeDrop() {
    if (checkPlayer() == true) {
        for (int i = 0; i < numberOfObjects; i++) {
            if ( objs[i].locationOfObject == playerInventory) {
                objs[i].locationOfObject = locationOfPlayer;
                printf("%s dropped.\n", objs[i].objName);
                break;
            }
        }
    } else {
        printf("You have nothing to drop!\n");
    }
}
