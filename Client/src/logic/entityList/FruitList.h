/* --------------------------------------------------------------------
 * File: FruitList.h
 * author: @estalvgs1999 & chuzz
 * Description: This file implements a linked list for fruits.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_FRUITLIST_H
#define CLIENT_FRUITLIST_H

// Libraries
#include <windef.h>
#include <stdlib.h>
#include "../../entity/Fruit.h"

struct FruitNode{
    struct Fruit* _fruit;
    struct FruitNode* _next;
};

static struct FruitNode* fruit_head;

// List Functions
void insertFruit(struct Fruit* new_fruit);
void deleteFruit(int key);

// Getters
struct Fruit* getFruit(int iPos,int jPos);
struct FruitNode* getFruitHead();

#endif //CLIENT_FRUITLIST_H
