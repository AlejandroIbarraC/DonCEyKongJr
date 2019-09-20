//
// Created by Jesus on 19/9/2019.
//
#ifndef KEYDONCE_COCODRILELOGIC_H
#define KEYDONCE_COCODRILELOGIC_H

struct cocodrile{

    int key;

    int iD;
    int jPos;
    int iPos;
    int onVine;
    int onField;
    int whichCoco; //O equal to blue Coco and 1 equal to red Coco//
    int cocoSpeed;
    int onScreen;
    int mouth;
    int viewR;
    int viewL;
    int viewD;
    int viewU;
};

void cocodrileMovement();

#endif //KEYDONCE_COCODRILELOGIC_H
