#ifndef player_h
#define player_h

#include <stdbool.h>

// creates player struct
struct player {
    int locationOfPlayer;
    const int playerInventory;
    char name[50];
    int playerTime;
};

// allows variables to be used elsewhere
extern struct player player;

// allows functions to be used elsewhere
extern bool checkPlayer();
extern int getHeldObject();
extern void executeInventory();

#endif
