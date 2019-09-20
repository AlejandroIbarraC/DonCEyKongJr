//
// Created by Jesus on 19/9/2019.
//

#ifndef KEYDONCE_COCODRILELIST_H
#define KEYDONCE_COCODRILELIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static struct cocodrileNode *head = NULL;
static struct cocodrileNode *current = NULL;

struct cocodrileNode {
    struct cocodrile* fruit;
    struct cocodrileNode *next;
};

void insertFirst(struct cocodrile* fruit);
struct cocodrileNode* returnHead();







#endif //KEYDONCE_COCODRILELIST_H
