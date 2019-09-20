//
// Created by Jesus on 19/9/2019.
//

#ifndef KEYDONCE_COCODRILELIST_H
#define KEYDONCE_COCODRILELIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CrocodrileLogic.h"

static struct crocodrileNode *head = NULL;

struct crocodrileNode {

    struct crocodrile *crocodrile;
    struct crocodrileNode *next;

};

/**
 *
 * @param fruit
 */
void insertFirst(struct crocodrile* fruit);

/**
 *
 * @param key
 * @return
 */
struct crocodrile* delete_Fruit(int key);

/**
 *
 * @param key
 * @return
 */
struct crocodrileNode* find_Fruit(int key);

/**
 *
 * @return
 */
struct crocodrileNode* returnHead_crocodrile();







#endif //KEYDONCE_COCODRILELIST_H
