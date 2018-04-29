#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// user made libraries
#include "event.h"
#include "object.h"
#include "container.h"

// booleans to check status of needed objects inside of trapdoor container
bool hasCircle = false;
bool hasSquare = false;
bool hasTriangle = false;
bool hasStar = false;

// function to check if all needed objects are in trapdoor to win
bool didWin() {
    if (circle->locationOfObject == trapdoor->containInventory) {
        hasCircle = true;
    }
    if (square->locationOfObject == trapdoor->containInventory) {
        hasSquare = true;
    }
    if (triangle->locationOfObject == trapdoor->containInventory) {
        hasTriangle = true;
    }
    if (star->locationOfObject == trapdoor->containInventory) {
        hasStar = true;
    }
    // if all objects are in trapdoor return true
    if (hasCircle && hasSquare && hasTriangle && hasStar) {
        return true;

    // if not re-initialize and return false
    } else {
        hasCircle = false;
        hasSquare = false;
        hasTriangle = false;
        hasStar = false;
        return false;
    }
}

// function to process game specific events runs inside after executePut in main
bool eventProcessing(const char * noun) {
    // if object is put in bookshelf
    if (!strcmp(noun, "bookshelf")) {
        // checks if book was put in bookshelf if so changes bookshelf description
        // and puts circle in room with bookshelf
        if (book->locationOfObject == bookshelf->containInventory) {
            bookshelf->containDesc = "a large bookshelf with all of it's books";
            circle->locationOfObject = bookshelf->locationOfContainer;
            printf("%s falls off of the bookshelf into the center of the room.\n", circle->objDescription);
        }
    // checks if battery was put in robot if so changes robot description 
    // and puts square in room with robot
    } else if (!strcmp(noun, "robot")) {
        if (battery->locationOfObject == robot->containInventory) {
            robot->containDesc = "a heavy robot that is now fully powered";
            square->locationOfObject = robot->locationOfContainer;
            printf("The robot powers on and moves across the room revealing\n"
            "%s on the floor.\n", square->objDescription);
        }
    // checks if chair was put in desk if so changes desk description and 
    // puts triangle into room with desk
    } else if (!strcmp(noun, "desk")) {
        if (chair->locationOfObject == desk->containInventory) {
            desk->containDesc = "a small desk";
            triangle->locationOfObject = desk->locationOfContainer;
            printf("As you slide the chair into the desk %s falls\n"
            "from under the chair onto the floor.\n", triangle->objDescription);
        }
    // if object was put into trapdoor check for win condition 
    // if game is won return true else return false
    } else if (!strcmp(noun, "trapdoor")) {
        if (didWin()) {
            return true;
        }
    } else {
        return false;
    }
    // all events except trapdoor will return false
    return false;
}









