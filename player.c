#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "object.h"

struct player player = {
    0,          // player score
    7           // playerInventory
};

// function to check if player is carrying an object, returns a boolean true if player has object
bool checkPlayer() {
    // loops through objects and checks if object location equals player inventory
    for (int i = 0; i < numberOfObjects; i++) {
        if (objs[i].locationOfObject == player.playerInventory) return true;
    }
    return false;
}

int getHeldObject() {
    for (int i = 0; i < numberOfObjects; i++) {
        if (objs[i].locationOfObject == player.playerInventory) return i;
    }
    return -1;
}

void executeInventory() {
    if (checkPlayer()) {
        printf("You are holding %s.\n", objs[getHeldObject()].objName);
    } else {
        printf("You aren't holding anything.\n");
    }
}

