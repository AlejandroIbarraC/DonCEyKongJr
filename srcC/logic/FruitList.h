//
// Created by Jesus on 19/9/2019.
//

#ifndef KEYDONCE_FRUITLIST_H
#define KEYDONCE_FRUITLIST_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


static struct fruitNode *head = NULL;
static struct fruitNode *current = NULL;

struct fruitNode{
    struct fruit* fruit;
    struct fruitNode* next;
};
void insertFirst();
struct fruitNode* returnHead();





#endif //KEYDONCE_FRUITLIST_H
