#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "container.h"
#include "player.h"
#include "object.h"

// creates array of containers
struct container contain[] = {
//  {description, name, ability to move, inventoryNumber, location, capacity}
    {"a trapdoor with 6 locks", "trapdoor", false, 8, 0, 1},
    {"a small desk", "desk", false, 9, 4, 4}
};

// creates an integer value of the number of containers
int numberOfContainers = (sizeof(contain) / sizeof(*contain));
// bool for determining if the object was placed in a container
bool objectPlaced = false;
// function for finding the amount of objects currently in a container
int objectsInContainer(int inventoryNumber) {
    int objCount = 0;
    for (int i = 0; i < numberOfObjects; i++) {
        if (inventoryNumber == objs[i].locationOfObject) objCount++;
    }
    return objCount;
}

// mechanic for placing inventory item into a specified container
void executePut(const char * noun) {
    // if container is not specified
    if (!noun) {
        printf("You must specify what you want to put your item in!\n");
        return;
    }
    // check if player is holding object
    else if (checkPlayer()) {
        // if player is holding object get held object
        for (int i = 0; i < numberOfContainers; i++) {
            // check if there is a container with the same name as noun and if it is in the same room as player
            if (!strcmp(noun, contain[i].containName) && player.locationOfPlayer == contain[i].locationOfContainer) {
                if (objectsInContainer(contain[i].containInventory) < contain[i].containCapacity) {
                    // change locationOfObject to containInventory
                    printf("You placed %s in %s.\n", objs[getHeldObject()].objName, contain[i].containName);
                    objs[getHeldObject()].locationOfObject = contain[i].containInventory;
                    objectPlaced = true;
                    return;
                } else {
                    printf("The %s is full!\n", contain[i].containName);
                }
            }
        }
        if (!objectPlaced) printf("%s is not in this room.\n", noun);
        objectPlaced = false; // re-init object placed
    } else {
        printf("You must be holding something to be able to put it in something!\n");
    }
}

