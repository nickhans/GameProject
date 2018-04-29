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

void eventProcessing(const char * noun) {
    if (!strcmp(noun, "bookshelf")) {
        printf("Was put in bookshelf");
    } else if (!strcmp(noun, "robot")) {
        printf("Was put in robot");
    } else if (!strcmp(noun, "desk")) {
        printf("Was put in desk");
    } else if (!strcmp(noun, "trapdoor")) {
        if (didWin()) {}
    } else {
        printf("Was put in other");
        return;
    }
}









