//
// Created by Jesus on 19/9/2019.
//
#ifndef KEYDONCE_COCODRILELOGIC_H
#define KEYDONCE_COCODRILELOGIC_H

struct crocodrile{

    int key;

    int iD;
    int jPos;
    int iPos;
    int onVine;
    int onField;
    int whichCroc; //O equal to blue Coco and 1 equal to red Coco//
    int crocSpeed;
    int onScreen;
    int mouth;
    int viewR;
    int viewL;
    int viewD;
    int viewU;
};

void crocodrileMovement();

#endif //KEYDONCE_COCODRILELOGIC_H
