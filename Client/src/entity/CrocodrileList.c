//
// Created by Jesus on 19/9/2019.
//

//insert link at the first location
#include "CrocodrileList.h"

void insertFirstC(struct crocodrile* crocodrile) {
    //create a link
    struct crocodrileNode *link = (struct cocodrileNode *) malloc(sizeof(struct crocodrileNode));

    link->crocodrile = crocodrile;

    //point it to old first cocodrileNode
    link->next = head;

    //point first to new first cocodrileNode
    head = link;
}

//find_Fruit a link with given key
struct crocodrileNode* findC(int key) {

    //start from the first link
    struct crocodrileNode *current = head;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->crocodrile->key != key) {

        //if it is last fruit
        if(current->next == NULL) {
            return NULL;
        } else {
            //go to next link
            current = current->next;
        }
    }

    //if data found, return the current Link
    return current;
}

struct crocodrile* deleteC(int key) {

    //start from the first link
    struct crocodrileNode* current = head;
    struct crocodrileNode* previous = NULL;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->crocodrile->key != key) {

        //if it is last fruit
        if(current->next == NULL) {
            return NULL;
        } else {
            //store reference to current link
            previous = current;
            //move to next link
            current = current->next;
        }
    }

    //found a match, update the link
    if(current == head) {
        //change first to point to next link
        head = head->next;
    } else {
        //bypass the current link
        previous->next = current->next;
    }

    return current->crocodrile;
}


struct crocodrileNode* returnHead_crocodrile(){
    return head;
}
