/* --------------------------------------------------------------------
 * File: FruitList.c
 * author: @estalvgs1999 & chuzz
 * Header: FruitList.c
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#include "FruitList.h"

void insertFruit(struct Fruit* new_fruit){
    struct FruitNode* tmp = (struct FruitNode*) malloc(sizeof(struct FruitNode));
    tmp->_fruit = new_fruit;
    tmp->_next = fruit_head;
    fruit_head = tmp;
}

void deleteFruit(int key){
    struct FruitNode* current = fruit_head;
    struct FruitNode* previous = NULL;
    if (fruit_head == NULL) {
        return;
    }
    while(current->_fruit->key != key) {
        if(current->_next == NULL) {
            return;
        } else {
            previous = current;
            current = current->_next;
        }
    }
    if(current == fruit_head) {
        fruit_head = fruit_head->_next;
    } else {
        previous->_next = current->_next;
    }
}

struct Fruit* getFruit(int iPos, int jPos){
    struct FruitNode* tmp = fruit_head;
    if (fruit_head == NULL) {
        return NULL;
    }
    while(tmp->_fruit->iPos != i && tmp->_fruit->jPos != jPos) {
        if(tmp->_next == NULL) {
            return NULL;
        } else {
            tmp = tmp->_next;
        }
    }
    return tmp->_fruit;
}

struct FruitNode* getFruitHead(){
    return fruit_head;
}