//
// Created by Jesus on 19/9/2019.
//

//insert link at the first location
#include "CocodrileList.h"

/*void insertFirst(struct cocodrile* cocodrile) {
    //create a link
    struct cocodrileNode *link = (struct cocodrileNode*) malloc(sizeof(struct cocodrileNode));

    link->fruit = cocodrile;

    //point it to old first cocodrileNode
    link->next = head;

    //point first to new first cocodrileNode
    head = link;
}

//find a link with given key
struct fruit* find(fruit key) {

    //start from the first link
    struct fruit* current = head;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->key != key) {

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

struct fruit* delete(int key) {

    //start from the first link
    struct fruit* current = head;
    struct fruit* previous = NULL;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->key != key) {

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

    return current;
}

struct cocodrileNode* returnHead(){
    return head;
}*/
