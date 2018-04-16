#ifndef location_h
#define location_h

// struct for locations containing a description, name, and room number
struct location {
    const char * description;
    const char * name;
    int roomNumber;
};

// defines each location in locs array to a pointer to that location
#define center (locs + 0)
#define room1 (locs + 1)
#define room2 (locs + 2)
#define room3 (locs + 3)
#define room4 (locs + 4)
#define room5 (locs + 5)
#define room6 (locs + 6)

// allow these variables to be used elsewhere
extern struct location locs[];
extern int numberOfLocations;

// allow these functions to be used elsewhere
extern void executeExamine(const char * noun);
extern void executeGo(const char * noun);

#endif
