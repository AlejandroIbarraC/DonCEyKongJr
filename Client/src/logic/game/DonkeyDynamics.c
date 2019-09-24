/* --------------------------------------------------------------------
 * File: DonkeyDynamics.c
 * author: @estalvgs1999 & chuzz
 * Header: GameKinetics.h
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#include "DonkeyDynamics.h"

/* ------------------------------------------------------------
 *                       DONKEY WALK
 * ------------------------------------------------------------*/
void dynamics_DKJrWalkRight(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    int currentSprite = 0;

    if (jPos < COLS - 1 && matrix[iPos][jPos + donkeyJr->speed] == (int*) empty_Box){

        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) empty_Box;
        jPos += donkeyJr->speed;
        donkeyJr->jPos = jPos;
        switch (currentSprite){
            case 421:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            case 422:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            case 423:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            case 411:
                matrix[iPos][jPos] = (int*) dkjr_WR2;
                break;
            case 412:
                matrix[iPos][jPos] = (int*) dkjr_WR3;
                break;
            case 413:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            default:
                break;

        }
        if (matrix[iPos + 1][jPos] == 0){
            donkeyJr->falling = 1;
        }
        goto end;
    }
    else if (jPos < COLS - 1 && (matrix[iPos][jPos + donkeyJr->speed] == (int*) 21 || matrix[iPos][jPos + donkeyJr->speed] == (int*) 22)){

        donkeyJr->donkeyLives--;
        donkeyJr->isDead = 1;
        struct Crocodile* crocodile = getCroc(iPos, jPos + donkeyJr->speed);
        crocodile->onScreen = 0;
        matrix[iPos][jPos + donkeyJr->speed] = (int*) empty_Box;
        goto end;
    }
    else if (jPos < COLS - 1 && (matrix[iPos][jPos + donkeyJr->speed] == (int*) _apple ||
    matrix[iPos][jPos + donkeyJr->speed] == (int*) _banana ||
    matrix[iPos][jPos + donkeyJr->speed] == (int*) _mango)){

        struct Fruit* delFruit = getFruit(iPos, jPos + donkeyJr->speed);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) empty_Box;
        jPos += donkeyJr->speed;
        donkeyJr->jPos = jPos;
        switch (currentSprite){
            case 421:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            case 422:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            case 423:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            case 411:
                matrix[iPos][jPos] = (int*) dkjr_WR2;
                break;
            case 412:
                matrix[iPos][jPos] = (int*) dkjr_WR3;
                break;
            case 413:
                matrix[iPos][jPos] = (int*) dkjr_WR1;
                break;
            default:
                break;

        }
        if (matrix[iPos + 1][jPos] == 0){
            donkeyJr->falling = 1;
        }
        goto end;
    }
    else{
        goto end;
    }
    end:
    return;
}

void dynamics_DKJrWalkLeft(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){

    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    int currentSprite = 0;
    
    if (jPos > 0 && matrix[iPos][jPos - donkeyJr->speed] == (int*) empty_Box){
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) empty_Box;
        jPos -= donkeyJr->speed;
        donkeyJr->jPos = jPos;
        switch (currentSprite){
            case 411:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            case 412:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            case 413:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            case 421:
                matrix[iPos][jPos] = (int*) dkjr_WL2;
                break;
            case 422:
                matrix[iPos][jPos] = (int*) dkjr_WL3;
                break;
            case 423:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            default:
                break;
        }
        if (matrix[iPos + 1][jPos] == (int*) empty_Box){
            donkeyJr->falling = 1;
        }
        goto end;
    }
    else if (jPos > 0 && (matrix[iPos][jPos - donkeyJr->speed] == (int*) 21 || matrix[iPos][jPos - donkeyJr->speed] == (int*) 22)){
        donkeyJr->donkeyLives--;
        donkeyJr->isDead = 1;
        struct Crocodile* crocodile = getCroc(iPos, jPos - donkeyJr->speed);
        crocodile->onScreen = 0;
        matrix[iPos][jPos - donkeyJr->speed] = (int*) empty_Box;
        goto end;
    }
    else if (jPos > 0 && (matrix[iPos][jPos - donkeyJr->speed] == (int*) _apple ||
    matrix[iPos][jPos - donkeyJr->speed] == (int*) _banana ||
    matrix[iPos][jPos - donkeyJr->speed] == (int*) _mango)){

        struct Fruit* delFruit = getFruit(iPos, jPos - donkeyJr->speed);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) empty_Box;
        jPos -= donkeyJr->speed;
        donkeyJr->jPos = jPos;
        switch (currentSprite){
            case 411:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            case 412:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            case 413:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            case 421:
                matrix[iPos][jPos] = (int*) dkjr_WL2;
                break;
            case 422:
                matrix[iPos][jPos] = (int*) dkjr_WL3;
                break;
            case 423:
                matrix[iPos][jPos] = (int*) dkjr_WL1;
                break;
            default:
                break;

        }
        if (matrix[iPos + 1][jPos] == 0){
            donkeyJr->falling = 1;
        }
        goto end;
    }else{
        goto end;
    }
    end:
    return;
}

/* ------------------------------------------------------------
 *                       DONKEY CLIMB
 * ------------------------------------------------------------*/
void dynamics_DKJrUp(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    int currentSprite = 0;

    if (iPos > 0 && matrix[iPos - donkeyJr->speed][jPos] == (int*) bg_vine){
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        switch (currentSprite){
            case 431:
                matrix[iPos][jPos] = (int*)  dkjr_CL2;
                break;
            case 432:
                matrix[iPos][jPos] = (int*) dkjr_CL1;
                break;
            default:
                break;
        }
        goto end;
    }else if (iPos > 0 && (matrix[iPos - donkeyJr->speed][jPos] == (int*) 21 || matrix[iPos - donkeyJr->speed][jPos] == (int*) 22)){
        donkeyJr->donkeyLives--;
        donkeyJr->isDead = 1;
        struct Crocodile* crocodile = getCroc(iPos - donkeyJr->speed, jPos);
        crocodile->onScreen = 0;
        matrix[iPos - donkeyJr->speed][jPos] = (int*) bg_vine;
        goto end;
    }else if (iPos > 0 && (matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_mango)){
        struct Fruit* delFruit = getFruit(iPos - donkeyJr->speed, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        switch (currentSprite){
            case 431:
                matrix[iPos][jPos] = (int*) dkjr_CL2;
                break;
            case 432:
                matrix[iPos][jPos] = (int*) dkjr_CL1;
                break;
            default:
                break;
        }
        goto end;
    }else{
        goto end;
    }
    end:
    return;
}

void dynamics_DKJrDown(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){

    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    int currentSprite = 0;

    if (iPos < ROWS - 1 && matrix[iPos + 1][jPos] == (int*) bg_vine){
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        switch (currentSprite){
            case 431:
                matrix[iPos][jPos] = (int*) dkjr_CL2;
                break;
            case 432:
                matrix[iPos][jPos] = (int*) dkjr_CL1;
                break;
            default:
                break;
        }
        goto end;
    }
    else if (iPos < ROWS - 1 && (matrix[iPos + donkeyJr->speed][jPos] == (int*) 21 || matrix[iPos + donkeyJr->speed][jPos] == (int*) 22)){
        donkeyJr->donkeyLives--;
        donkeyJr->isDead = 1;
        struct Crocodile* crocodile = getCroc(iPos + donkeyJr->speed, jPos);
        crocodile->onScreen = 0;
        matrix[iPos + donkeyJr->speed][jPos] = (int*) bg_vine;
        goto end;
    }
    else if (iPos < ROWS - 1 && (matrix[iPos + donkeyJr->speed][jPos] == (int*) vine_apple ||
    matrix[iPos + donkeyJr->speed][jPos] == (int*) vine_banana ||
    matrix[iPos + donkeyJr->speed][jPos] == (int*) vine_mango)){

        struct Fruit* delFruit = getFruit(iPos + donkeyJr->speed, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        switch (currentSprite){
            case 431:
                matrix[iPos][jPos] = (int*) dkjr_CL2;
                break;
            case 432:
                matrix[iPos][jPos] = (int*) dkjr_CL1;
                break;
            default:
                break;
        }
        goto end;
    }
    else{
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->falling = 1;
        goto end;
    }
    
    end:
    return;
}

/* ------------------------------------------------------------
 *                       DONKEY JUMPS
 * ------------------------------------------------------------*/
void dynamics_DKJrJumpUp(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;

    if (iPos > 0 && matrix[iPos - donkeyJr->speed][jPos] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && (matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && (matrix[iPos - donkeyJr->speed][jPos] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) _mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->airUp = 1;
        goto end;
    }
    else if (iPos > 0 && (matrix[iPos - donkeyJr->speed][jPos] == (int*) bg_tree || matrix[iPos - donkeyJr->speed][jPos] == (int*) bg_floor)){
        goto end;
    }
    else{
        donkeyJr->airUp = 1;
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        goto end;
    }
    end:
    return;
}

void dynamics_DKJrJumpRight(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;

    if (iPos > 0 && jPos < COLS - 1 && matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->airR = 1;
        goto end;
    }else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_floor ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_tree)){
        goto end;
    }else{
        donkeyJr->airR = 1;
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        goto end;
    }
    
    end:
    return;
}

void dynamics_DKJrJumpLeft(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    
    if (iPos > 0 && jPos > 0 && matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_mango)){
       
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _mango)){
        
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JL;
        donkeyJr->airL = 1;
        goto end;
    }
    else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_floor ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_tree)){
        goto end;
    }else{
        donkeyJr->airL = 1;
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JL;
        goto end;
    }
    end:
    return;
}

void dynamics_DKJrJumpRightToVine(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    
    if (iPos > 0 && jPos < COLS - 1 && matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_mango)){
        
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _mango)){
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->airR = 1;
        goto end;
    }else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_floor ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_tree)){
        matrix[iPos][jPos] = (int*) bg_vine;
        jPos += donkeyJr->speed;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->falling = 1;
        goto end;
    }else{
        donkeyJr->airR = 1;
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        goto end;
    }
    end:
    return;
}

void dynamics_DKJrJumpLeftToVine(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    
    if (iPos > 0 && jPos > 0 && matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_mango)){
        
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
        goto end;
    }
    else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _mango)){
        
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JL;
        donkeyJr->airL = 1;
        goto end;
    }
    else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_floor ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_tree)){
        matrix[iPos][jPos] = (int*) bg_vine;
        jPos -= donkeyJr->speed;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JL;
        donkeyJr->falling = 1;
        goto end;
    }
    else{
        donkeyJr->airL = 1;
        matrix[iPos][jPos] = (int*) bg_vine;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JL;
        goto end;
    }

    end:
    return;
}

/* ------------------------------------------------------------
 *                       DONKEY AIR
 * ------------------------------------------------------------*/
void dynamics_DKJrAirUp(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    
    if (iPos > 0 && matrix[iPos - donkeyJr->speed][jPos] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
    }
    else if (iPos > 0 && (matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) vine_mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
    }
    else if (iPos > 0 && (matrix[iPos - donkeyJr->speed][jPos] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos] == (int*) _mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->falling = 1;
    }else{
        donkeyJr->falling = 1;
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
    }

}

void dynamics_DKJrAirRight(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    
    if (iPos > 0 && jPos < COLS - 1 && matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
    }
    else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) vine_mango)){
        
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
    }
    else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) _mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->falling = 1;
    }
    else if (iPos > 0 && jPos < COLS - 1 && (matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_floor ||
    matrix[iPos - donkeyJr->speed][jPos + donkeyJr->speed] == (int*) bg_tree)) {
        matrix[iPos][jPos] = (int*) bg_vine;
        jPos += donkeyJr->speed;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
        donkeyJr->falling = 1;
    }
    else{
        donkeyJr->falling = 1;
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos += donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JR;
    }
}

void dynamics_DKJrAirLeft(struct DKJr* donkeyJr ,int* matrix[ROWS][COLS]){
    int iPos = donkeyJr->iPos;
    int jPos = donkeyJr->jPos;
    
    if (iPos > 0 && jPos > 0 && matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_vine){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
    }else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_apple ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_banana ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) vine_mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_CL1;
        donkeyJr->onVine = 1;
    }else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _apple ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _banana ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) _mango)){
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        struct Fruit* delFruit = getFruit(iPos, jPos);
        donkeyJr->donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        matrix[iPos][jPos] = (int*) dkjr_JL;
        donkeyJr->falling = 1;
    }else if (iPos > 0 && jPos > 0 && (matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_floor ||
    matrix[iPos - donkeyJr->speed][jPos - donkeyJr->speed] == (int*) bg_tree)){
        matrix[iPos][jPos] = (int*) bg_vine;
        jPos -= donkeyJr->speed;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JL;
        donkeyJr->falling = 1;
    }else{
        donkeyJr->falling = 1;
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos -= donkeyJr->speed;
        jPos -= donkeyJr->speed;
        donkeyJr->iPos = iPos;
        donkeyJr->jPos = jPos;
        matrix[iPos][jPos] = (int*) dkjr_JL;
    }
}