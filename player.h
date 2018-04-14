#ifndef player_h
#define player_h

#include <stdbool.h>

// creates player struct
struct player {
    int playerScore;
    const int playerInventory;
};

// allows variables to be used elsewhere
extern struct player player;

// allows functions to be used elsewhere
extern bool checkPlayer();
extern int getHeldObject();
extern void executeInventory();

#endif
