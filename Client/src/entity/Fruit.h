/* --------------------------------------------------------------------
 * File: Fruit.h
 * author: @estalvgs1999 & @chuzz
 * Description: Header containing the Fruit struct.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_FRUIT_H
#define CLIENT_FRUIT_H

struct Fruit{

    // Fruit properties
    int id; //Identifies the struct (2)
    int key; //Number of Fruit
    int f_type; // apple::31 >> banana::32 >> mango::33
    int points;

    // Positions in matrix (i,j)
    int iPos,jPos;

    // Space Location >> 1: true | 0: false
    int onScreen, onVine, placed;

};

#endif //CLIENT_FRUIT_H
