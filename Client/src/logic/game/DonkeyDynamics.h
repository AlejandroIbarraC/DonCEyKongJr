/* --------------------------------------------------------------------
 * File: DonkeyDynamics.h
 * author: @estalvgs1999 & chuzz
 * Description: In this file all the logic related to the movement of
 *              entities is programmed.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_DONKEYDYNAMICS_H
#define CLIENT_DONKEYDYNAMICS_H

#include "../data/codes.h"
#include "../../entity/DKJr.h"
#include "../../entity/Fruit.h"
#include "../../entity/Crocodile.h"
#include "../entityList/FruitList.h"
#include "../entityList/CrocList.h"

#define ROWS 24
#define COLS 16

// Donkey Horizontal
void dynamics_DKJrWalkRight(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);
void dynamics_DKJrWalkLeft(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);

// Donkey Vertical
void dynamics_DKJrUp(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);
void dynamics_DKJrDown(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);

// Donkey Jumps
void dynamics_DKJrJumpUp(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);
void dynamics_DKJrJumpRight(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);
void dynamics_DKJrJumpLeft(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);

void dynamics_DKJrJumpRightToVine(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);
void dynamics_DKJrJumpLeftToVine(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);

// Donkey Air Dynamic
void dynamics_DKJrAirUp(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);
void dynamics_DKJrAirRight(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);
void dynamics_DKJrAirLeft(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]);



#endif //CLIENT_DONKEYDYNAMICS_H
