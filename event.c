#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "event.h"

void eventProcessing(const char * noun) {
    if (!strcmp(noun, "bookshelf")) {
        printf("Was put in bookshelf");
    } else if (!strcmp(noun, "robot")) {
        printf("Was put in robot");
    } else if (!strcmp(noun, "desk")) {
        printf("Was put in desk");
    } else {
        printf("Was put in other");
        return;
    }
}







