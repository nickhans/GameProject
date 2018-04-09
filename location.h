#ifndef location_h
#define location_h

struct location {
    const char * description;
    const char * name;
};

extern struct location locs[];

#define center (locs + 0)
#define room1 (locs + 1)
#define room2 (locs + 2)
#define room3 (locs + 3)
#define room4 (locs + 4)
#define room5 (locs + 5)
#define room6 (locs + 6)

extern void executeLook(const char * noun);
extern void executeGo(const char * noun);

#endif
