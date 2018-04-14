#ifndef container_h
#define container_h

#include <stdbool.h>

// creates a struct for containers
struct container {
    const char * containDesc;
    const char * containName;
    const bool canMove;
    const int containNumber; // starting after 7 (player)
    int locationOfContainer;
};

// allows variables to be used elsewhere
extern struct container contain[];
extern int numberOfContainers;

#endif
