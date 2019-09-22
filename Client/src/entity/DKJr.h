/* --------------------------------------------------------------------
 * File: DKJr.h
 * author: @estalvgs1999 & @chuzz
 * Description: Header containing the Donkey Kong Jr struct.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_DKJR_H
#define CLIENT_DKJR_H

struct DKJr{

    // Donkey properties
    int isDead; // 1: true | 0: false
    int donkeyPoints; // Amount of points
    int donkeyLives; // Remaining lives

    // Positions in matrix (i,j)
    int iPos,jPos;

    // Space Location >> 1: true | 0: false
    int onScreen, onVine;

    // Movement properties
    int speed;
    int falling;
    int airUp, airR, airL;
};

#endif //CLIENT_DKJR_H
