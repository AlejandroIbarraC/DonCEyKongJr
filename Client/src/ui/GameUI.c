/* --------------------------------------------------------------------
 * File: GameUI.c
 * author: @estalvgs1999 & chuzz
 * Header: GameUI.h
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/

#include "GameUI.h"
#include "../logic/game/Game.h"
#include "../logic/entityList/CrocList.h"
#include "../logic/entityList/FruitList.h"

// Wrapper function to initialize matrix from csv file
void init_Matrix(){
    initGameMatrix(matrix);
}

// Main drawing function
int draw_Matrix(int key_code,ALLEGRO_DISPLAY* display, ALLEGRO_BITMAP* bitmap){

    // At init creates the thread for ui
    /*if(first_time){
        thread = al_create_thread(sock_Thread, "");
        al_start_thread(_thread);
        first_time = 0;
    }*/

    al_hold_bitmap_drawing(true);
    al_draw_bitmap(bitmap,0,0,0);

    // Enviroment
    draw_Water();
    draw_Ground();
    draw_Floor();
    draw_Vine();

    // Secondary Characters
    /*draw_Mario();
    draw_DonkeyKong();

    // Entities
    draw_Fruit();
    draw_Croc();*/
    draw_DKJr();

    al_hold_bitmap_drawing(false);
    al_flip_display();
    al_set_target_bitmap(al_get_backbuffer(display));

    // Updates Matrix State
    flag = upd_GameMatrix(key_code,matrix);

    return 0;
}

/* -----------------------------------------------------------------------
 *                         DRAW ENVIRONMENT
 * -----------------------------------------------------------------------*/

void draw_Water(){
    bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/water.png");
    int j = 0;
    for (j = 0; j < 16; j++){
        al_draw_bitmap(bitmap, calc_Xpos(j), calc_Ypos(23), 0);
    }
}

void draw_Floor(){
    bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/platform.png");
    ALLEGRO_BITMAP *floor = al_load_bitmap("../src/ui/img/sprites/enviroment/floor.png");
    int j = 0;
    for (j = 4; j < 6; j++){
        al_draw_bitmap(bitmap, calc_Xpos(j), calc_Ypos(2), 0);
    }
    for (j = 0; j < 9; j++){
        al_draw_bitmap(bitmap, calc_Xpos(j), calc_Ypos(4), 0);
    }
    for (j = 8; j < 12; j++){
        al_draw_bitmap(bitmap, calc_Xpos(j), calc_Ypos(5), 0);
    }
    al_draw_bitmap(bitmap, calc_Xpos(2), calc_Ypos(9), 0);
    for (j = 11; j < 16; j++){
        al_draw_bitmap(bitmap, calc_Xpos(j), calc_Ypos(13), 0);
    }
    for (j = 2; j < 4; j++){
        al_draw_bitmap(bitmap, calc_Xpos(j), calc_Ypos(15), 0);
    }
    for (j = 0; j < 3; j++){
        al_draw_bitmap(floor, calc_Xpos(j), calc_Ypos(22), 0);
    }
}

void draw_Ground(){
    ALLEGRO_BITMAP *gndR = al_load_bitmap("../src/ui/img/sprites/enviroment/groundright.png");
    ALLEGRO_BITMAP *gndL = al_load_bitmap("../src/ui/img/sprites/enviroment/groundleft.png");
    int j = 0;

    al_draw_bitmap(gndR,calc_Xpos(6), calc_Ypos(20), 0);
    al_draw_bitmap(gndL,calc_Xpos(5), calc_Ypos(20), 0);


    al_draw_bitmap(gndR,calc_Xpos(9), calc_Ypos(21), 0);
    al_draw_bitmap(gndL,calc_Xpos(8), calc_Ypos(21), 0);

    al_draw_bitmap(gndR,calc_Xpos(12), calc_Ypos(20), 0);
    al_draw_bitmap(gndL,calc_Xpos(11), calc_Ypos(20), 0);

    al_draw_bitmap(gndR,calc_Xpos(15), calc_Ypos(19), 0);
    al_draw_bitmap(gndL,calc_Xpos(14), calc_Ypos(19), 0);
}

void draw_Vine(){
    ALLEGRO_BITMAP *vine = al_load_bitmap("../src/ui/img/sprites/enviroment/vine2.png");
    ALLEGRO_BITMAP *leaf = al_load_bitmap("../src/ui/img/sprites/enviroment/vine_leaf2.png");
    int i = 0;
    int parity = 0;
    for (i = 5; i < 21; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(0), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(0), calc_Ypos(i), 0);
            parity = 1;
        }

    }
    for (i = 10; i < 13; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(2), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(2), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 16; i < 21; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(2), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(2), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 5; i < 18; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(4), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(4), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 0; i < 2; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(6), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(6), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 5; i < 14; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(6), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(6), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 6; i < 18; i++){

        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(8), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(8), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 6; i < 16; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(10), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(10), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 0; i < 11; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(12), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(12), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 0; i < 11; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(14), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(14), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 14; i < 18; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(12), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(12), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    for (i = 14; i < 18; i++){
        if(parity){
            al_draw_bitmap(leaf, calc_Xpos(14), calc_Ypos(i), 0);
            parity = 0;
        }else{
            al_draw_bitmap(vine, calc_Xpos(14), calc_Ypos(i), 0);
            parity = 1;
        }
    }
    al_draw_bitmap(leaf, calc_Xpos(9), calc_Ypos(0), 0);
}

/* -----------------------------------------------------------------------
 *                            DRAW ENTITIES
 * -----------------------------------------------------------------------*/

void draw_DKJr(){
    struct DKJr* localDKJr = getDonkey();
    int iPos = localDKJr->iPos;
    int jPos = localDKJr->jPos;
    bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
    al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
    switch ((int)matrix[iPos][jPos]) {
        case 411:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/walk_right1.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
        case 412:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/walk_right2.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos - 1), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
        case 413:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/walk_right3.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos - 1), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
        case 421:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/walk_left1.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos + 1), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
        case 422:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/walk_left2.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos + 1), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
        case 423:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/walk_left3.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos + 1), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
        case 431:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/onvine.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            break;
        case 432:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/onvine.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            break;
        case 441:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/jumpright.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
        case 442:
            bitmap = al_load_bitmap("../src/ui/img/sprites/movement/jumpleft.png");
            al_draw_bitmap(bitmap, calc_Xpos(jPos), calc_Ypos(iPos), 0);
            if (iPrev != iPos || jPrev != jPos){
                bitmap = al_load_bitmap("../src/ui/img/sprites/enviroment/empty.png");
                al_draw_bitmap(bitmap, calc_Xpos(jPrev), calc_Ypos(iPrev), 0);
            }
            break;
    }
    iPrev = iPos;
    jPrev = jPos;
}



/* -----------------------------------------------------------------------
 *                         MATH CODE :)
 * -----------------------------------------------------------------------*/
int calc_Xpos(int j){
    int posX = j * 44;
    return posX;
}

int calc_Ypos(int i){
    int posY = i * 29;
    return posY;
}