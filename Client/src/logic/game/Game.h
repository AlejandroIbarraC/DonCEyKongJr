/* --------------------------------------------------------------------
 * File: Game.h
 * author: @estalvgs1999 & chuzz
 * Description: File containing the main methods of game mechanics
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_GAME_H
#define CLIENT_GAME_H

// Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../data/codes.h"
#include "../../entity/DKJr.h"
#include "../../entity/Crocodile.h"
#include "../entityList/CrocList.h"
#include "../entityList/FruitList.h"
#include "DonkeyDynamics.h"

#define ROWS 24
#define COLS 16

// Donkey Kong Jr main instance
static struct DKJr donkeyJr = {0,0,3,21,0,0,1,0,0,0,0};

void initGameMatrix(int* matrix[ROWS][COLS]);

// Functions that execute constant updates of the game matrix
int upd_GameMatrix(int key_code,int* matrix[ROWS][COLS]);
void upd_Fruits(int* matrix[ROWS][COLS]);
void upd_Crocs(int* matrix[ROWS][COLS]);

// Other Util Functions
void search_VineCroc(struct Crocodile* crocodile,int* matrix[ROWS][COLS]);
void print_Status(int* matrix[ROWS][COLS]);
void reset_DKJr(int* matrix[ROWS][COLS]);
struct DKJr* getDonkey();

// Move Wrapper Functions :: The deep code is in GameKinetics.h

// Crocodile Movements
void move_CrocVine(struct Crocodile* crocodile,int* matrix[ROWS][COLS]);
void move_CrocFall(struct Crocodile* crocodile,int* matrix[ROWS][COLS]);

// Donkey Kong Jr Movements
void move_DonkeyWalk(int key_code,int* matrix[ROWS][COLS]);
void move_DonkeyClimb(int key_code,int* matrix[ROWS][COLS]);
void move_DonkeyAir(int air_code,int* matrix[ROWS][COLS]);
void move_DonkeyFall(int* matrix[ROWS][COLS]);


#endif //CLIENT_GAME_H
