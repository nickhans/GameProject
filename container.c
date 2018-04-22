#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
// bool for determining if there is a container in the room
bool containerInRoom = false;
// bool to determine if object was in container
bool objectInContainer = false;

// function for finding the amount of objects currently in a container
int objectsInContainer(int inventoryNumber) {
    int objCount = 0;
    for (int i = 0; i < numberOfObjects; i++) {
        if (inventoryNumber == objs[i].locationOfObject) objCount++;
    }
    return objCount;
}
// function to check if given noun is a container
bool isContainer(const char * noun) {
    for (int i = 0; i < numberOfContainers; i++) {
        if (!strcmp(noun, contain[i].containName)) return true;
    }
    return false;
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
                // checks if the amount of objects in the container is less than the capacity
                if (objectsInContainer(contain[i].containInventory) < contain[i].containCapacity) {
                    // change locationOfObject to containInventory
                    printf("You put the %s in %s.\n", objs[getHeldObject()].objName, contain[i].containName);
                    objs[getHeldObject()].locationOfObject = contain[i].containInventory;
                    objectPlaced = true;
                    return;
                } else {
                    printf("The %s is full! An object must be removed before one can be placed!\n", contain[i].containName);
                }
            }
        }
        if (!objectPlaced) printf("%s is not in this room.\n", noun);
        objectPlaced = false; // re-init object placed
    // if player is holding nothing
    } else {
        printf("You must be holding something to be able to put it in something!\n");
    }
}
// mechanic for removing object from container and putting it in player inventory
void executeRemove(const char * noun) {
    // checks if there is any containers in the room
    for (int i = 0; i < numberOfContainers; i++) {
        if (contain[i].locationOfContainer == player.locationOfPlayer) {
            containerInRoom = true;
        }
    }
    // if there are no containers
    if (!containerInRoom) {
        printf("There is nothing in this room that can hold objects!\n");
        containerInRoom = false; // reset containerInRoom
        return;
    } else containerInRoom = false; // reset containerInRoom

    // checks for valid noun input of object
    if (!noun) {
        printf("You must specify what object you want to remove!\n");
        return;
    }

    // if the player is not holding an object
    if (!checkPlayer()) {
        // gets input from player for container name
        char removalTemp[50];
        printf("Remove from where?\n> ");
        fgets(removalTemp, sizeof(removalTemp), stdin);
        char * removal = strtok(removalTemp, " \n"); // reformats the player input into a useable format
        // checks if user input is a valid container
        if (!isContainer(removal)) {
            printf("%s is not a valid container!\n", removal);
            return;
        } else { 
            for (int i = 0; i < numberOfContainers; i++) {
                // checks if container is in same room as player
                if (!strcmp(removal, contain[i].containName) && contain[i].locationOfContainer == player.locationOfPlayer) {
                    for (int j = 0; j < numberOfObjects; j++) {
                        // checks for objects in the container with the same name as noun
                        if (!strcmp(noun, objs[j].objName) && objs[j].locationOfObject == contain[i].containInventory) {
                            // changes object location to player inventory
                            objs[j].locationOfObject = player.playerInventory;
                            printf("%s was removed from %s.\n", objs[getHeldObject()].objName, contain[i].containName);
                            objectInContainer = true;
                            break;
                        }
                    }
                    containerInRoom = true;
                }
            }
            // if no objects were removed object was not in container
            if (!objectInContainer) printf("%s is not in the %s!\n", noun, removal);
            // if no containers found container is not in that room
            if (!containerInRoom) printf("%s is not in this room!\n", removal);
            containerInRoom = false;    // reset containerInRoom
            objectInContainer = false;  // reset objectInContainer
        }
    // if player is holding an object   
    } else {
        printf("You cannot remove an object while you are holding one!\n");
    }
}

