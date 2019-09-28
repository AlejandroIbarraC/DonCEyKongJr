
#include "CrocodileNode.h"
#include <stdlib.h>

/**
 * Metodo para insertar un kremlin
 * @param kremlin
 */
void insertKremlin(struct Crocodile* kremlin){
    struct CrocodileNode* tmp = (struct CrocodileNode*) malloc(sizeof(struct CrocodileNode));
    tmp->kremlin = kremlin;
    tmp->next = kremlinHead;
    kremlinHead = tmp;
}

/**
 * Metodo para eliminar un kremlin por id
 * @param id
 */
void deleteKremlinByID(int id){
    struct CrocodileNode* current = kremlinHead;
    struct CrocodileNode* previous = NULL;
    if (kremlinHead == NULL) {
        return;
    }
    while(current->kremlin->id != id) {
        if(current->next == NULL) {
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }
    if(current == kremlinHead) {
        kremlinHead = kremlinHead->next;
    } else {
        previous->next = current->next;
    }
}

/**
 * Metodo para eliminar un kremlin por posicion
 * @param i
 * @param j
 */
void deleteKremlinByPos(int i, int j){
    struct CrocodileNode* current = kremlinHead;
    struct CrocodileNode* previous = NULL;
    if (kremlinHead == NULL) {
        return;
    }
    while(current->kremlin->posI != i && current->kremlin->posJ) {
        if(current->next == NULL) {
            return;
        } else {
            previous = current;
            current = current->next;
        }
    }
    if(current == kremlinHead) {
        kremlinHead = kremlinHead->next;
    } else {
        previous->next = current->next;
    }
}

/**
 * Metodo para buscar un kremlin por posicion
 * @param i
 * @param j
 * @return el kremlin
 */
struct Crocodile* findKremlinByPos(int i, int j){
    struct CrocodileNode* tmp = kremlinHead;
    if (kremlinHead == NULL) {
        return NULL;
    }
    while(tmp->kremlin->posI != i && tmp->kremlin->posJ != j) {
        if(tmp->next == NULL) {
            return NULL;
        } else {
            tmp = tmp->next;
        }
    }
    return tmp->kremlin;
}

/**
 * Metodo para obtener la cabeza de los kremlins
 * @return cabeza de los kremlins
 */
struct CrocodileNode* returnKremlinHead(){
    return kremlinHead;
}
