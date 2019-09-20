//
// Created by Jesus on 19/9/2019.
//

#ifndef KEYDONCE_COCODRILELIST_H
#define KEYDONCE_COCODRILELIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CocodrileLogic.h"

static struct cocodrileNode *head = NULL;

struct cocodrileNode {

    struct cocodrile *cocodrile;
    struct cocodrileNode *next;

};

/**
 *
 * @param fruit
 */
void insertFirst(struct cocodrile* fruit);

/**
 *
 * @param key
 * @return
 */
struct cocodrile* delete(int key);

/**
 *
 * @param key
 * @return
 */
struct cocodrileNode* find(int key);

/**
 *
 * @return
 */
struct cocodrileNode* returnHead();







#endif //KEYDONCE_COCODRILELIST_H
