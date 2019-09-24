/* --------------------------------------------------------------------
 * File: CrocList.c
 * author: @estalvgs1999 & chuzz
 * Header: CrocList.c
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#include "CrocList.h"
void insertCroc(struct Crocodile* new_croc){
    struct CrocNode* tmp = (struct CrocNode*) malloc(sizeof(struct CrocNode));
    tmp->_croc = new_croc;
    tmp->_next = croc_head;
    croc_head = tmp;
}

void deleteCroc(int key){
    struct CrocNode* current = croc_head;
    struct CrocNode* previous = NULL;
    if (croc_head == NULL) {
        return;
    }
    while(current->_croc->key != key) {
        if(current->_next == NULL) {
            return;
        } else {
            previous = current;
            current = current->_next;
        }
    }
    if(current == croc_head) {
        croc_head = croc_head->_next;
    } else {
        previous->_next = current->_next;
    }
}

struct Crocodile* getCroc(int iPos, int jPos){
    struct CrocNode* tmp = croc_head;
    if (croc_head == NULL) {
        return NULL;
    }
    while(tmp->_croc->iPos != iPos && tmp->_croc->jPos != jPos) {
        if(tmp->_next == NULL) {
            return NULL;
        } else {
            tmp = tmp->_next;
        }
    }
    return tmp->_croc;
}

struct CrocNode* getCrocHead(){
    return croc_head;
}