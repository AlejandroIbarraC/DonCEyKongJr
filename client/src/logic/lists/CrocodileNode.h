

#ifndef DONCEYKONGJR_CROCODILENODE_H
#define DONCEYKONGJR_CROCODILENODE_H

#include "../entity/Crocodile.h"
#include <windef.h>


static struct CrocodileNode* kremlinHead = NULL;

struct CrocodileNode{
    struct Crocodile* kremlin;
    struct CrocodileNode* next;
};

void insertKremlin(struct Crocodile* kremlin);
void deleteKremlinByID(int id);
void deleteKremlinByPos(int i, int j);
struct Crocodile* findKremlinByPos(int i, int j);
struct CrocodileNode* returnKremlinHead();

#endif //DONCEYKONGJR_CROCODILENODE_H
