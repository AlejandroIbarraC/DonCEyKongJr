/* --------------------------------------------------------------------
 * File: codes.h
 * author: @estalvgs1999
 * Description: This file contains variables with the code that represents
 *              the sprites in the logical matrix of the game.
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#ifndef CLIENT_CODES_H
#define CLIENT_CODES_H

// Basic background elements ::00XX
static int empty_Box = 0;
static int bg_tree = 11;
static int bg_floor = 12;
static int bg_vine = 13;
static int bg_mario = 5;
static int bg_Donkey = 6;
static int bg_key = 7;

// Red Crocodile ::21XX
static int red_CrocUpClose = 2111;
static int red_CrocUpOpen = 2112;
static int red_CrocDwClose = 2121;
static int red_CrocDwOpen = 2122;
static int red_CrocLfClose = 2131;
static int red_CrocLfOpen = 2132;
static int red_CrocRtClose = 2141;
static int red_CrocRtOpen = 2142;

// Blue Crocodrile ::22XX
static int blue_CrocUpClose = 2211;
static int blue_CrocUpOpen = 2212;
static int blue_CrocDwClose = 2221;
static int blue_CrocDwOpen = 2222;
static int blue_CrocLfClose = 2231;
static int blue_CrocLfOpen = 2232;
static int blue_CrocRtClose = 2241;
static int blue_CrocRtOpen = 2242;

// Fruit ::03XX
static int _apple = 311;
static int vine_apple = 312;
static int _banana = 321;
static int vine_banana = 322;
static int _mango = 331;
static int vine_mango = 332;

// Donkey Kong Jr ::04XX

// Walk Right
static int dkjr_WR1 = 411;
static int dkjr_WR2 = 412;
static int dkjr_WR3 = 413;

// Walk Left
static int dkjr_LR1 = 421;
static int dkjr_LR2 = 422;
static int dkjr_LR3 = 423;

// Climb onVine
static int dkjr_CL1 = 431;
static int dkjr_CL2 = 432;

// Jumping
static int dkjr_JR = 441;
static int dkjr_JL = 442;

#endif //CLIENT_CODES_H
