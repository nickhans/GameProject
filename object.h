#ifndef object_h
#define object_h

struct object {
    const char * objDescription;
    const char * objName;
    int locationOfObject;
};

//creates objects
extern struct object objs[];
extern int numberOfObjects;

extern void executeTake(const char * noun);
extern void executeDrop();

#endif
