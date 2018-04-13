#ifndef player_h
#define player_h

#include <stdbool.h>

struct player {
    int playerScore;
    const int playerInventory;
};

extern struct player player;

extern bool checkPlayer();
extern int getHeldObject();
extern void executeInventory();

#endif
