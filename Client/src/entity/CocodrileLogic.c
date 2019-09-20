//
// Created by Jesus on 19/9/2019.
//
#include "CocodrileLogic.h"
#include "CocodrileList.h"

void cocodrileMovement(){
    struct cocodrileNode* tmp = returnHead();
    struct cocodrile* cocodrile;
    int iD = 1;
    int iPos = 0;
    int jPos = 0;
    int cocoSpeed = 0;
    int whichCoco = 0;
    int onScreen = 1;
    int viewR;
    int viewL;
    int viewD;
    int viewU;
    int onVine;
    int onField;
    static int gameMatrix[24][16];
    while (tmp != NULL){
        cocodrile = tmp->cocodrile;
        iD = cocodrile->iD;
        iPos = cocodrile->iPos;
        jPos = cocodrile->jPos;
        cocoSpeed = cocodrile->cocoSpeed;
        whichCoco = cocodrile->whichCoco;
        onScreen = cocodrile->onScreen;
        onVine = cocodrile->onVine;
        onField = cocodrile->onField;
        viewR = cocodrile->viewR;
        viewL = cocodrile->viewL;
        viewD = cocodrile->viewD;
        viewU = cocodrile->viewU;
        if(gameMatrix[iPos][jPos+1] != 0 && gameMatrix[iPos][jPos+1] != 2){
            gameMatrix[iPos][jPos+1] = gameMatrix[iPos][jPos];
            gameMatrix[iPos][jPos] = 0;

            viewR = 1;
            viewL = 0;
            viewD = 0;
            viewU = 0;

            onField = 1;
            onVine = 0;
        }
        else if(gameMatrix[iPos][jPos] == 2){
            if(whichCoco == 0){
                if(gameMatrix[iPos+1][jPos] == 0){
                    onScreen = 0;
                }
                else{
                    gameMatrix[iPos+1][jPos] = gameMatrix[iPos][jPos];
                    gameMatrix[iPos][jPos] = 2;
                    onScreen = 1;
                    viewR = 0;
                    viewL = 0;
                    viewD = 1;
                    viewU = 0;
                    onField = 1;
                    onVine = 0;
                }
            }
            else{
                if(gameMatrix[iPos+1][jPos] == 0){
                    gameMatrix[iPos-1][jPos] = gameMatrix[iPos][jPos];
                    gameMatrix[iPos][jPos] = 2;
                    viewR = 0;
                    viewL = 0;
                    viewD = 0;
                    viewU = 1;
                    onField = 0;
                    onVine = 1;
                }
                else{
                    gameMatrix[iPos+1][jPos] = gameMatrix[iPos][jPos];
                    gameMatrix[iPos][jPos] = 2;
                    viewR = 0;
                    viewL = 0;
                    viewD = 1;
                    viewU = 0;
                    onField = 0;
                    onVine = 1;
                }
            }
        }
        else if(gameMatrix[iPos][jPos+1]== 0){
            gameMatrix[iPos][jPos-1] = gameMatrix[iPos][jPos];
            gameMatrix[iPos][jPos] = 0;
            viewR = 0;
            viewL = 1;
            viewD = 0;
            viewU = 0;
            onField = 1;
            onVine = 0;
        }
    }
}
