#ifndef object_h
#define object_h

#include <stdbool.h>

// creates a struct for objects
struct object {
    const char * objDescription;
    const char * objName;
    int locationOfObject;
};

#define circle (objs + 0)
#define square (objs + 1)
#define triangle (objs + 2)
#define star (objs + 3)
#define book (objs + 4)
#define chair (objs + 5)
#define battery (objs + 6)

// allows variables to be used elsewhere
extern struct object objs[];
extern int numberOfObjects;
extern bool isObject(const char * noun);

// allows functions to be used elsewhere
extern void executeTake(const char * noun);
extern void executeDrop(const char * noun);

#endif
