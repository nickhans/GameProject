#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "event.h"
#include "object.h"
#include "container.h"

bool hasCircle = false;
bool hasSquare = false;
bool hasTriangle = false;
bool hasStar = false;

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
    if (hasCircle && hasSquare && hasTriangle && hasStar) {
        return true;
    } else {
        hasCircle = false;
        hasSquare = false;
        hasTriangle = false;
        hasStar = false;
        return false;
    }
}

bool eventProcessing(const char * noun) {
    if (!strcmp(noun, "bookshelf")) {
        if (book->locationOfObject == bookshelf->containInventory) {
            circle->locationOfObject = bookshelf->locationOfContainer;
            printf("%s falls off of the bookshelf into the center of the room.\n", circle->objDescription);
        }
    } else if (!strcmp(noun, "robot")) {
        if (battery->locationOfObject == robot->containInventory) {
            square->locationOfObject = robot->locationOfContainer;
            printf("The robot powers on and moves across the room revealing\n"
            "%s on the floor.\n", square->objDescription);
        }
    } else if (!strcmp(noun, "desk")) {
        if (chair->locationOfObject == desk->containInventory) {
            triangle->locationOfObject = desk->locationOfContainer;
            printf("As you slide the chair into the desk %s falls\n"
            "from under the chair onto the floor.\n", triangle->objDescription);
        }
    } else if (!strcmp(noun, "trapdoor")) {
        if (didWin()) {
            return true;
        }
    } else {
        return false;
    }
    return false;
}









