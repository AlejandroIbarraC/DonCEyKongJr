/* --------------------------------------------------------------------
 * File: Game.c
 * author: @estalvgs1999 & chuzz
 * Header: Game.h
 * version: 0.1
 * ITCR™ - sabrosos3G®
 * --------------------------------------------------------------------*/
#include "Game.h"

/* Read the matrix of a .csv file and convert it into an array of
 * integers in two dimensions */
void initGameMatrix(int* matrix[ROWS][COLS]){
    char buffer[1024] ;
    char path[1000] = "..\\src\\logic\\data\\matrix.csv";
    char *record,*line;

    FILE *fstream;
    fstream = fopen(path,"r");
    if(fstream == NULL)
    {
        perror("\n file opening failed ");
        goto end;
    }

    for(int i = 0 ; i < ROWS; i++){
        line=fgets(buffer,sizeof(buffer),fstream);
        record = strtok(line,",");
        const char *rec = record;

        for(int j = 0;j < COLS; j++){
            const char *s = record;
            int val;
            sscanf(s,"%d",&val);
            matrix[i][j] = (int*)val;
            record = strtok(NULL, ",");
        }

    }
    fclose(fstream);

    end:
    return;
}


// Cycle updating the matrix
int upd_GameMatrix(int key_code, int* matrix[ROWS][COLS]) {

    // Donkey wins
    if ((donkeyJr.iPos == 0 && donkeyJr.jPos >= 7) ||
        (donkeyJr.iPos == 1 && donkeyJr.jPos == 4) ||
        (donkeyJr.iPos == 1 && donkeyJr.jPos == 5)) {
        key_code = 0;
        donkeyJr.donkeyLives++;
        reset_DKJr(matrix);
    }
    // Donkey Died
    if (donkeyJr.isDead) {
        key_code = 0;
        reset_DKJr(matrix);
    }
    // Falling
    if (donkeyJr.falling >= 1) {
        key_code = 0;
        move_DonkeyFall(matrix);
    }

    // Jumps ↑::10 ; ←::11;  →::12
    if (donkeyJr.airUp) {
        move_DonkeyAir(10, matrix);
        key_code = 0;
        donkeyJr.airUp = 0;
    }
    if (donkeyJr.airL) {
        move_DonkeyAir(11, matrix);
        key_code = 0;
        donkeyJr.airL = 0;
    }
    if (donkeyJr.airR) {
        move_DonkeyAir(12, matrix);
        key_code = 0;
        donkeyJr.airR = 0;
    }

    // Climbing
    if (key_code != 0) {
        if (donkeyJr.onVine)
            move_DonkeyClimb(key_code, matrix);
        else
            move_DonkeyWalk(key_code, matrix);
    }

    // Fruits and Crocs
    if (getCrocHead() != NULL)
        upd_Crocs(matrix);

    if (getFruitHead() != NULL)
        upd_Fruits(matrix);

    return 0;
}

/* -----------------------------------------------------------------------
 *                         ENTITIES UPDATING
 * -----------------------------------------------------------------------*/
// Cycle updating the Fruit List
void upd_Fruits(int* matrix[ROWS][COLS]){

    struct FruitNode* f_Node = getFruitHead();
    struct Fruit* _fruit;

    int iPos,jPos;

    // Iterates over FruitList
    while(f_Node != NULL){
        _fruit = f_Node->_fruit;

        // Remove from Screen
        if(! _fruit->onScreen){
            deleteFruit(_fruit->key);
            f_Node = f_Node->_next;
        } else{
            iPos = _fruit->iPos;
            jPos = _fruit->jPos;

            if(_fruit->placed)
                f_Node = f_Node->_next;
            // Fruit on Vine
            else if(matrix[iPos][jPos] == (int*) bg_vine){
                switch (_fruit->f_type){
                    case 31:
                        matrix[iPos][jPos] = (int*)vine_apple;
                        break;
                    case 32:
                        matrix[iPos][jPos] = (int*)vine_banana;
                        break;
                    case 33:
                        matrix[iPos][jPos] = (int*)vine_mango;
                        break;
                }
                _fruit->placed = 1;
                f_Node = f_Node->_next;
            }
            else if(matrix[iPos][jPos] == (int*) empty_Box){
                switch (_fruit->f_type){
                    case 31:
                        matrix[iPos][jPos] = (int*)_apple;
                        break;
                    case 32:
                        matrix[iPos][jPos] = (int*)_banana;
                        break;
                    case 33:
                        matrix[iPos][jPos] = (int*)_mango;
                        break;
                }
                _fruit->placed = 1;
                f_Node = f_Node->_next;
            }
            else
                _fruit->onScreen = 0;
        }
    }
}

// Cycle updating the Crocodiles List
void upd_Crocs(int* matrix[ROWS][COLS]) {
    struct CrocNode *c_Node = getCrocHead();
    struct Crocodile *_croc;

    // Iterates over Crocs List
    while (c_Node != NULL) {
        _croc = c_Node->_croc;

        //
        if (_croc->onScreen == 0) {
            deleteCroc(_croc->id);
            c_Node = c_Node->_next;
        } //
        else if (_croc->falling >= 1) {
            move_CrocFall(_croc, matrix);
            c_Node = c_Node->_next;
        } //
        else if (_croc->placed == 0) {
            if (matrix[_croc->iPos][_croc->jPos] == (int *) empty_Box &&
                (matrix[_croc->iPos + 1][_croc->jPos] == (int *) bg_tree ||
                 matrix[_croc->iPos + 1][_croc->jPos] == (int *) bg_floor)) {
                switch (_croc->color) {
                    // Red Crocodrile
                    case 21:
                        matrix[_croc->iPos][_croc->jPos] = (int *) red_CrocRtClose;
                        break;
                        // Blue Crocodrile
                    case 22:
                        matrix[_croc->iPos][_croc->jPos] = (int *) blue_CrocRtClose;
                        break;
                }
                _croc->placed = 1;
                c_Node = c_Node->_next;
            } else if (matrix[_croc->iPos][_croc->jPos] == (int *) bg_vine) {
                switch (_croc->color) {
                    case 21:
                        matrix[_croc->iPos][_croc->jPos] = (int *) red_CrocDwClose;
                        break;
                    case 22:
                        matrix[_croc->iPos][_croc->jPos] = (int *) blue_CrocDwClose;
                        break;
                }
                _croc->placed = 1;
                c_Node = c_Node->_next;
            } else if (matrix[_croc->iPos + 1][_croc->jPos] == (int *) empty_Box) {
                switch (_croc->color) {
                    case 21:
                        matrix[_croc->iPos][_croc->jPos] = (int *) red_CrocRtClose;
                        break;
                    case 22:
                        matrix[_croc->iPos][_croc->jPos] = (int *) blue_CrocRtClose;
                        break;
                }
                _croc->placed = 1;
                _croc->falling = 1;
                c_Node = c_Node->_next;
            } else {
                _croc->onScreen = 0;
                c_Node = c_Node->_next;
            }
        } else if (_croc->onVine == 0) {
            search_VineCroc(_croc, matrix);
            c_Node = c_Node->_next;
        } else {
            move_CrocVine(_croc, matrix);
            c_Node = c_Node->_next;
        }
    }
}

// Looks for a vine where Croc can down
void search_VineCroc(struct Crocodile* crocodile,int* matrix[ROWS][COLS]){
    int iPos = crocodile->iPos;
    int jPos = crocodile->jPos;
    crocodile->iPrev = iPos;
    crocodile->jPrev = jPos;
    int currentSprite = 0;
    if (iPos < ROWS - 2 && matrix[iPos + 2][jPos] == (int *) bg_vine){
        crocodile->speed = 1;
        crocodile->iPos += 2;
        crocodile->onVine = 1;
        matrix[iPos][jPos] = (int *) empty_Box;
        if (crocodile->color == 21){
            matrix[crocodile->iPos][jPos] = (int *) red_CrocDwClose;
        }else{
            matrix[crocodile->iPos][jPos] = (int *) blue_CrocDwClose;
        }
    }else if (jPos < (COLS - abs(crocodile->speed)) &&
              (matrix[iPos + abs(crocodile->speed)][jPos + crocodile->speed] == (int *) bg_tree ||
               matrix[iPos + abs(crocodile->speed)][jPos + crocodile->speed] == (int *) bg_floor)){
        crocodile->jPos += crocodile->speed;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int *) empty_Box;
        if (crocodile->color == 21){
            switch (currentSprite){
                case 2141:
                    matrix[iPos][crocodile->jPos] = (int *) red_CrocRtOpen;
                    break;
                case 2142:
                    matrix[iPos][crocodile->jPos] = (int *) red_CrocRtClose;
                    break;
                case 2131:
                    matrix[iPos][crocodile->jPos] = (int *) red_CrocLfOpen;
                    break;
                case 2132:
                    matrix[iPos][crocodile->jPos] = (int*) red_CrocLfClose;
                    break;
            }
        }else{
            switch (currentSprite){
                case 2241:
                    matrix[iPos][crocodile->jPos] = (int *) blue_CrocRtOpen;
                    break;
                case 2242:
                    matrix[iPos][crocodile->jPos] = (int *) blue_CrocRtClose;
                    break;
                case 2231:
                    matrix[iPos][crocodile->jPos] = (int *) blue_CrocLfOpen;
                    break;
                case 2232:
                    matrix[iPos][crocodile->jPos] = (int*) blue_CrocLfClose;
                    break;
            }
        }
    }else{
        crocodile->speed *= -1;
        crocodile->jPos += crocodile->speed;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int *) empty_Box;
        if (crocodile->color == 21){
            switch (currentSprite){
                case 2131:
                    matrix[iPos][crocodile->jPos] = (int *) red_CrocRtOpen;
                    break;
                case 2132:
                    matrix[iPos][crocodile->jPos] = (int *) red_CrocRtClose;
                    break;
                case 2141:
                    matrix[iPos][crocodile->jPos] = (int *) red_CrocLfOpen;
                    break;
                case 2142:
                    matrix[iPos][crocodile->jPos] = (int*) red_CrocLfClose;
            }
        }else{
            switch (currentSprite){
                case 2231:
                    matrix[iPos][crocodile->jPos] = (int *) blue_CrocLfOpen;
                    break;
                case 2232:
                    matrix[iPos][crocodile->jPos] = (int *) blue_CrocLfClose;
                    break;
                case 2241:
                    matrix[iPos][crocodile->jPos] = (int *) blue_CrocLfOpen;
                    break;
                case 2242:
                    matrix[iPos][crocodile->jPos] = (int*) blue_CrocLfClose;
            }
        }
    }
}

/* -----------------------------------------------------------------------
 *                         CROCODILE DYNAMICS
 * -----------------------------------------------------------------------*/
// Crocodile Movement in a Vine
void move_CrocVine(struct Crocodile* crocodile,int* matrix[ROWS][COLS]){
    // Set crocodile config
    int iPos = crocodile->iPos;
    int jPos = crocodile->jPos;
    crocodile->iPrev = iPos;
    crocodile->jPrev = jPos;
    int currentSprite = 0;

    // Crocodile movement on Vine
    if (matrix[iPos + crocodile->speed][jPos] == (int*) bg_vine) {
        crocodile->iPos += crocodile->speed;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) bg_vine;

        // Red crocodile on vine
        if (crocodile->color == 21){
            switch (currentSprite){
                case 2121:
                    matrix[crocodile->iPos][jPos] = (int*) red_CrocDwOpen;
                    break;
                case 2122:
                    matrix[crocodile->iPos][jPos] = (int*) red_CrocDwClose;
                    break;
                case 2111:
                    matrix[crocodile->iPos][jPos] = (int*) red_CrocUpOpen;
                    break;
                case 2112:
                    matrix[crocodile->iPos][jPos] = (int*) red_CrocUpClose;
                    break;
            }
        }else{
            // Blue crocodile on vine
            switch (currentSprite){
                case 2221:
                    matrix[crocodile->iPos][jPos] = (int*) blue_CrocDwOpen;
                    break;
                case 2222:
                    matrix[crocodile->iPos][jPos] = (int*) blue_CrocDwClose;
                    break;
                case 2211:
                    matrix[crocodile->iPos][jPos] = (int*) blue_CrocUpOpen;
                    break;
                case 2212:
                    matrix[crocodile->iPos][jPos] = (int*) blue_CrocUpClose;
                    break;
            }
        }
    }
    // Crocodile catch DonkeyKong Jr on Vine
    else if (matrix[crocodile->iPos + crocodile->speed][jPos] == (int*) dkjr_CL1 ||
    matrix[crocodile->iPos + crocodile->speed][jPos] == (int*) dkjr_CL2){

        crocodile->onVine = 0;
        crocodile->onScreen = 0;
        donkeyJr.donkeyLives--;
        donkeyJr.isDead = 1;
        matrix[crocodile->iPos][jPos] = (int*) bg_vine;
        matrix[crocodile->iPos + crocodile->speed][jPos] = (int*) bg_vine;
    }
    // Crocodile find a Fruit or a platform
    else if (crocodile->color == 21 || matrix[crocodile->iPos + crocodile->speed][jPos] == (int*) vine_apple ||
    matrix[crocodile->iPos + crocodile->speed][jPos] == (int*) vine_banana || matrix[crocodile->iPos + crocodile->speed][jPos] == (int*) vine_mango ||
    matrix[crocodile->iPos + crocodile->speed][jPos] == (int*) bg_floor || matrix[crocodile->iPos + crocodile->speed][jPos] == (int*) bg_tree){

        crocodile->speed *= -1;
        crocodile->iPos += crocodile->speed;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) bg_vine;
        // Change his direction
        switch (currentSprite){
            case 2121:
                matrix[crocodile->iPos][jPos] = (int*) red_CrocUpOpen;
                break;
            case 2122:
                matrix[crocodile->iPos][jPos] = (int*) red_CrocUpClose;
                break;
            case 2111:
                matrix[crocodile->iPos][jPos] = (int*) red_CrocDwOpen;
                break;
            case 2112:
                matrix[crocodile->iPos][jPos] = (int*) red_CrocDwClose;
                break;
            case 2221:
                matrix[crocodile->iPos][jPos] = (int*) blue_CrocUpOpen;
                break;
            case 2222:
                matrix[crocodile->iPos][jPos] = (int*) blue_CrocUpClose;
                break;
            case 2211:
                matrix[crocodile->iPos][jPos] = (int*) blue_CrocDwOpen;
                break;
            case 2212:
                matrix[crocodile->iPos][jPos] = (int*) blue_CrocDwClose;
                break;
        }
    }
    // Crocodile Falling
    else{
        crocodile->onVine = 0;
        matrix[iPos][jPos] = (int*) bg_vine;
        crocodile->falling = 1;
    }
}

// Crocodile Movement when it falling
void move_CrocFall(struct Crocodile* crocodile,int* matrix[ROWS][COLS]){
    int iPos = crocodile->iPos;
    int jPos = crocodile->jPos;
    crocodile->iPrev = iPos;
    crocodile->jPrev = jPos;

    // Crococile arrives at the end of the vine
    if (matrix[crocodile->iPos + 1][crocodile->jPos] == (int*) empty_Box){
        crocodile->falling++;
        matrix[iPos][jPos] = (int*) empty_Box;
        crocodile->iPos++;
        switch (crocodile->color){
            case 21:
                matrix[crocodile->iPos][jPos] = (int*) red_CrocRtOpen;
                break;
            case 22:
                matrix[crocodile->iPos][jPos] = (int*) blue_CrocLfOpen;
                break;
        }
    }
    // Crocodile falls for another reason
    else{
        if (crocodile->falling >= 6){
            crocodile->onScreen = 0;
            matrix[iPos][jPos] = (int*) empty_Box;
        }else{
            crocodile->falling = 0;
            matrix[iPos][jPos] = (int*) empty_Box;
            switch (crocodile->color){
                case 21:
                    matrix[crocodile->iPos][jPos] = (int*) red_CrocRtClose;
                    break;
                case 22:
                    matrix[crocodile->iPos][jPos] = (int*) blue_CrocRtClose;
                    break;
            }
        }
    }
}

/* -----------------------------------------------------------------------
 *                         DONKEY JR DYNAMICS
 * -----------------------------------------------------------------------*/

// Donkey Jr Horizontal Movement
void move_DonkeyWalk(int key_code, int* matrix[ROWS][COLS]){
    switch(key_code){
        // DIR: Right
        case 1:
            dynamics_DKJrWalkRight(&donkeyJr,matrix);
            break;
        // DIR: Left
        case 2:
            dynamics_DKJrWalkLeft(&donkeyJr,matrix);
            break;
        // DIR: Jump Up
        case 3:
            dynamics_DKJrJumpUp(&donkeyJr,matrix);
            break;
        // DIR: Jump Left
        case 4:
            dynamics_DKJrJumpLeft(&donkeyJr,matrix);
            break;
        // DIR: Jump Right
        case 5:
            dynamics_DKJrJumpRight(&donkeyJr,matrix);
            break;
        default:
            break;

    }
}

// Donkey Jr Vertical Movement
void move_DonkeyClimb(int key_code, int* matrix[ROWS][COLS]){
    switch(key_code){
        // DIR: Jump Left to vine
        case 4:
            dynamics_DKJrJumpLeftToVine(&donkeyJr,matrix);
            break;
        // DIR: Jump Right to vine
        case 5:
            dynamics_DKJrJumpRightToVine(&donkeyJr,matrix);
            break;
        // DIR: Up
        case 6:
            dynamics_DKJrUp(&donkeyJr,matrix);
            break;
        // DIR: Down
        case 7:
            dynamics_DKJrDown(&donkeyJr,matrix);
            break;
        default:
            break;

    }
}

// The dynamics of Donkey when it is in the air
void move_DonkeyAir(int air_code, int* matrix[ROWS][COLS]){
    switch(air_code){
        // DIR: Air Up
        case 10:
            dynamics_DKJrAirUp(&donkeyJr,matrix);
            break;
        // DIR: Air Left
        case 11:
            dynamics_DKJrAirLeft(&donkeyJr,matrix);
            break;
        // DIR: Air Right
        case 12:
            dynamics_DKJrAirRight(&donkeyJr,matrix);
            break;
        default:
            break;

    }
}

// Donkey falling code :)
void move_DonkeyFall(int* matrix[ROWS][COLS]){
    int iPos = donkeyJr.iPos;
    int jPos = donkeyJr.jPos;
    int currentSprite = 0;
    if (iPos < ROWS - 1 && (matrix[iPos + donkeyJr.speed][jPos] == (int*) bg_floor || matrix[iPos + donkeyJr.speed][jPos] == (int*) bg_tree)){
        if (donkeyJr.falling > 6){
            donkeyJr.donkeyLives--;
            donkeyJr.isDead = 1;
            donkeyJr.falling = 0;
            donkeyJr.onVine = 0;
        }else{
            donkeyJr.falling = 0;
            donkeyJr.onVine = 0;
            matrix[iPos][jPos] = (int*) dkjr_WR1;
        }
    }else if (iPos < ROWS - 1 && (matrix[iPos + donkeyJr.speed][jPos] == (int*) _apple ||
    matrix[iPos + donkeyJr.speed][jPos] == (int*) _banana ||
    matrix[iPos + donkeyJr.speed][jPos] == (int*) _mango)){
        struct Fruit* delFruit = getFruit(iPos + donkeyJr.speed, jPos);
        donkeyJr.donkeyPoints += delFruit->points;
        delFruit->onScreen = 0;
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos += donkeyJr.speed;
        donkeyJr.iPos = iPos;
        matrix[iPos][jPos] = (int*) currentSprite;
        donkeyJr.falling++;
    }else if (iPos < ROWS - 1 && matrix[iPos + donkeyJr.speed][jPos] == (int*) empty_Box){
        currentSprite = (int) matrix[iPos][jPos];
        matrix[iPos][jPos] = (int*) empty_Box;
        iPos += donkeyJr.speed;
        donkeyJr.iPos = iPos;
        matrix[iPos][jPos] = (int*) currentSprite;
        donkeyJr.falling++;
    }else{
        donkeyJr.donkeyLives--;
        donkeyJr.isDead = 1;
    }
}

// Restore Donkey to the default Values
void reset_DKJr(int* matrix[ROWS][COLS]){
    // Donkey properties
    donkeyJr.isDead = 0;
    donkeyJr.airUp = 0;
    donkeyJr.airL = 0;
    donkeyJr.airR = 0;

    // Donkey Positions
    int initI= 21,initJ = 0;
    int prevI = donkeyJr.iPos,prevJ = donkeyJr.jPos;

    // If Donkey was on a vine, a vine is drawn at the position, else an empty box is drawn
    if(donkeyJr.onVine)
        matrix[prevI][prevJ] = (int*)bg_vine;
    else
        matrix[prevI][prevJ] = (int*)empty_Box;

    donkeyJr.iPos = initI;
    donkeyJr.jPos = initJ;
    matrix[initI][initJ] = (int*)dkjr_WR1;
}

// Returns an Donkey Pointer
struct DKJr* getDonkey(){
    return &donkeyJr;
}

/* -----------------------------------------------------------------------
 *                         OTHER UTIL FUNCS
 * -----------------------------------------------------------------------*/

// Prints the actual status of Matrix
void print_Status(int* matrix[ROWS][COLS]){
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            printf("%d ", (int) matrix[i][j]);
        }
        printf("\n");
    }
}
