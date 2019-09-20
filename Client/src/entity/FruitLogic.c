//
// Created by Jesus on 19/9/2019.
//

#include "FruitLogic.h"
#include "FruitList.h"

void fruitState() {
    struct fruitNode* tmp = returnHead_Fruit();
    struct fruit* fruit;
    int iD = 2;
    int iPos = 0;
    int jPos = 0;
    int whichFruit = 0;
    int onScreen = 1;
    int onVine;
    int onField;
    static int gameMatrix[24][16];
    while (tmp != NULL){
        fruit = tmp->fruit;
        iD = fruit->iD;
        iPos = fruit->iPos;
        jPos = fruit->jPos;
        whichFruit = fruit->whichFruit;
        onScreen = fruit->onScreen;
        onVine = fruit->onVine;
        onField = fruit->onField;
        if(gameMatrix[iPos][jPos+1]== 6){
            gameMatrix[iPos][jPos+1] = gameMatrix[iPos][jPos];
            gameMatrix[iPos][jPos] = 0;
            onScreen =0;
            onField = 1;
            onVine = 0;
        }
        else if(gameMatrix[iPos][jPos-1]== 6){
            gameMatrix[iPos][jPos-1] = gameMatrix[iPos][jPos];
            gameMatrix[iPos][jPos] = 0;
            onScreen =0;
            onField = 1;
            onVine = 0;
        }
        else if(gameMatrix[iPos+1][jPos]== 6){
            gameMatrix[iPos+1][jPos] = gameMatrix[iPos][jPos];
            gameMatrix[iPos][jPos] = 0;
            onScreen =0;
            onField = 0;
            onVine = 1;
        }
        else if(gameMatrix[iPos][jPos-1]== 6){
            gameMatrix[iPos-1][jPos] = gameMatrix[iPos][jPos];
            gameMatrix[iPos][jPos] = 0;
            onScreen =0;
            onField = 0;
            onVine = 1;
        }

    }
}
