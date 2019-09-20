//
// Created by Jesus on 19/9/2019.
//
#include "FruitList.h"

void insertFirst_Fruit(struct fruit *fruit) {
    //create a link
    struct fruitNode *link = (struct fruitNode*) malloc(sizeof(struct fruitNode));

    link->fruit = fruit;

    //point it to old first cocodrileNode
    link->next = head;

    //point first to new first cocodrileNode
    head = link;
}

//find_Fruit a link with given key
struct fruitNode* find_Fruit(int key) {

    //start from the first link
    struct fruitNode* current = head;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->fruit->key != key) {

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

struct fruit* delete_Fruit(int key) {

    //start from the first link
    struct fruitNode* current = head;
    struct fruitNode* previous = NULL;

    //if list is empty
    if(head == NULL) {
        return NULL;
    }

    //navigate through list
    while(current->fruit->key != key) {

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

    return current->fruit;
}

struct fruitNode* returnHead_Fruit() {
    return head;
}