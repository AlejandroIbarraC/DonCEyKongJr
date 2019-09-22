/* --------------------------------------------------------------------
 * File: Fruit.h
 * author: @estalvgs1999 & @chuzz
 * Description: Header containing the fruit struct.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_FRUIT_H
#define CLIENT_FRUIT_H

struct fruit{

    // Fruit properties
    int id; //Identifies the struct (2)
    int key; //Number of fruit
    int f_type; // apple::31 >> banana::32 >> mango::33
    int points;

    // Positions in matrix (i,j)
    int iPos,jPos;

    // Space Location >> 1: true | 0: false
    int onScreen, onVine, placed;

};

#endif //CLIENT_FRUIT_H
