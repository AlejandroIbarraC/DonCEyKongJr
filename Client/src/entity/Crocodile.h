/* --------------------------------------------------------------------
 * File: Crocodrile.h
 * author: @estalvgs1999 & @chuzz
 * Description: Header containing the crocodile struct.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_CROCODILE_H
#define CLIENT_CROCODILE_H

struct crocodile{

    // Croc properties
    int id; //Identifies the struct (1)
    int key; //Number of crocodile
    int color; // red::21 >> blue::22

    // Positions in matrix (i,j)
    int iPos,jPos;
    int iPrev,jPrev;

    // Space Location >> 1: true | 0: false
    int onScreen, onVine, placed;

    // Movement properties
    int speed;
    int falling;
};

#endif //CLIENT_CROCODILE_H
