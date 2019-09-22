/* --------------------------------------------------------------------
 * File: CrocList.h
 * author: @estalvgs1999 & chuzz
 * Description: This file implements a linked list for Crocodiles.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_CROCLIST_H
#define CLIENT_CROCLIST_H

// Libraries
#include <windef.h>
#include <stdlib.h>
#include "../../entity/Crocodile.h"

struct CrocNode{
    struct Crocodile* _croc;
    struct CrocNode* _next;
};

static struct CrocNode* croc_head;

// List Functions
void insertCroc(struct Crocodile* new_croc);
void deleteCroc(int key);

// Getters
struct Crocodile* getCroc(int iPos,int jPos);
struct CrocNode* getCrocHead();

#endif //CLIENT_CROCLIST_H
