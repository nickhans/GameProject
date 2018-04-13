#include <stdbool.h>
#include "container.h"

struct container contain[] = {
    {"a trapdoor with 6 locks", "trapdoor", false, 8, 0},
    {"a small desk", "desk", false, 9, 4}
};

int numberOfContainers = (sizeof(contain) / sizeof(*contain));

