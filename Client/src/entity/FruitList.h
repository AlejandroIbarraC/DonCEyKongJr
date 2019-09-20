//
// Created by Jesus on 19/9/2019.
//

#ifndef KEYDONCE_FRUITLIST_H
#define KEYDONCE_FRUITLIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FruitLogic.h"

//
struct fruitNode{
    struct fruit* fruit;
    struct fruitNode* next;
};

// Globals
static struct fruitNode *head = NULL;
static struct fruitNode *current = NULL;




void insertFirst_Fruit(struct fruit *fruit);
struct fruitNode* find_Fruit(int key);
struct fruit* delete_Fruit(int key);
struct fruitNode* returnHead_Fruit();





#endif //KEYDONCE_FRUITLIST_H
