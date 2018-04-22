#include <stdbool.h>
#include "container.h"

// creates array of containers
struct container contain[] = {
    {"a trapdoor with 6 locks", "trapdoor", false, 8, 0},
    {"a small desk", "desk", false, 9, 4}
};

// creates an integer value of the number of containers
int numberOfContainers = (sizeof(contain) / sizeof(*contain));

void executePut(const char * noun) {
    // check if object to put is being held

    // ask for container

    // check if container is in room

    // change locationOfObject to containInventory
}

